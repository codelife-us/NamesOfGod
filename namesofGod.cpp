// Names of God
//
// MIT License
//
// Copyright (c) 2026 Todd Birtcher
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// By Code Life, Todd Birtcher
// A simple program to list the Names of God in the Bible, along with their meanings and references.

#define VERSION "1.0"

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

struct NameOfGod {
    std::string name;
    std::string pronunciation;
    std::vector<std::string> references;
    std::string description;
    std::string meaning;
};

const std::array<NameOfGod, 19> namesOfGod = {{
    {
        "El, Eloah",
        "el, el-oh-ah",
        {"Nehemiah 9:17", "Psalm 139:19", "Genesis 31:29", "Numbers 23:19", "Deuteronomy 5:9", "Nehemiah 9:31"},
        "Mighty, Strong, Prominent",
        "Root meaning is power and might."
    },
    {
        "Elohim",
        "el-oh-heem",
        {"Genesis 1:1", "Genesis 17:7", "Jeremiah 31:33"},
        "Creator, Mighty and Strong",
        "Plural form reflecting the nature of the Trinity."
    },
    {
        "El Shaddai",
        "el-shah-dahy",
        {"Genesis 17:1", "Exodus 6:3", "Ruth 1:20"},
        "God Almighty, The Mighty One of Jacob",
        "Speaks to ultimate divine power."
    },
    {
        "Adonai",
        "ah-daw-nahy",
        {"Genesis 15:2", "Judges 6:15"},
        "Lord, Master",
        "Emphasizes an authoritative relationship and reverence."
    },
    {
        "YHWH / Yahweh / Jehovah",
        "yah-way / ji-hoh-veh",
        {"Exodus 3:14", "Exodus 3:15", "Deuteronomy 6:4", "Daniel 9:14"},
        "LORD",
        "The personal, proper name of God. I AM WHO I AM. Denotes his eternal presence and accessibility."
    },
    {
        "Yahweh-Jireh",
        "yah-way-ji-reh",
        {"Genesis 22:14"},
        "The Lord Will Provide",
        "Memorialized when God provided a ram as sacrifice in place of Isaac."
    },
    {
        "Yahweh-Rapha",
        "yah-way-raw-faw",
        {"Exodus 15:26"},
        "The Lord Who Heals",
        "Healing of body and soul."
    },
    {
        "Yahweh-Nissi",
        "yah-way-nee-see",
        {"Exodus 17:15"},
        "The Lord Our Banner",
        "A rallying place; commemorates God's victory over the Amalekites."
    },
    {
        "Yahweh-M'Kaddesh",
        "yah-way-meh-kad-esh",
        {"Leviticus 20:8", "Ezekiel 37:28"},
        "The Lord Who Sanctifies, Makes Holy",
        "Only God cleanses and sets apart his people."
    },
    {
        "Yahweh-Shalom",
        "yah-way-shah-lohm",
        {"Judges 6:24"},
        "The Lord Our Peace",
        "Name given by Gideon to the altar he built after God's reassurance."
    },
    {
        "Yahweh-Elohim",
        "yah-way-el-oh-him",
        {"Genesis 2:4", "Psalm 59:5"},
        "LORD God",
        "Combination name denoting his unique identity as both personal Lord and almighty God."
    },
    {
        "Yahweh-Tsidkenu",
        "yah-way-tzid-kay-noo",
        {"Jeremiah 33:16", "2 Corinthians 5:21"},
        "The Lord Our Righteousness",
        "Only God provides the righteousness required to stand before him."
    },
    {
        "Yahweh-Rohi",
        "yah-way-roh-hee",
        {"Psalm 23:1"},
        "The Lord Our Shepherd",
        "Drawn from David's own experience as a shepherd."
    },
    {
        "Yahweh-Shammah",
        "yah-way-sham-mahw",
        {"Ezekiel 48:35"},
        "The Lord Is There",
        "Indicates the return of God's glory to Jerusalem in the age to come."
    },
    {
        "Yahweh-Sabaoth",
        "yah-way-sah-bah-ohth",
        {"Isaiah 1:24", "Psalm 46:7"},
        "The Lord of Hosts",
        "Lord over all angels and humanity. Expresses supreme majesty and authority."
    },
    {
        "El Elyon",
        "el-el-yohn",
        {"Genesis 14:18-22", "Deuteronomy 32:8", "Psalm 7:17", "Psalm 57:2", "Psalm 97:9"},
        "Most High",
        "Denotes his exaltation and absolute sovereignty over all."
    },
    {
        "El Roi",
        "el-roh-ee",
        {"Genesis 16:13"},
        "God of Seeing",
        "The God who perceives our distress and sees all things. Named by Hagar."
    },
    {
        "El Olam",
        "el-oh-lahm",
        {"Psalm 90:1-3"},
        "Everlasting God",
        "Eternal, existing outside and beyond the constraints of time."
    },
    {
        "El Gibhor",
        "el-ghee-bohr",
        {"Isaiah 9:6", "Revelation 19:15"},
        "Mighty God",
        "Describes the Messiah as a powerful warrior who defeats his enemies."
    }
}};

static std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

void printList(const std::string& filter = "") {
    const std::string needle = toLower(filter);
    for (const auto& god : namesOfGod) {
        if (!needle.empty() && toLower(god.name).find(needle) == std::string::npos)
            continue;
        std::cout << "Name:          " << god.name << "\n";
        std::cout << "Pronunciation: " << god.pronunciation << "\n";
        std::cout << "References:    ";
        for (size_t i = 0; i < god.references.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << god.references[i];
        }
        std::cout << "\n";
        std::cout << "Description:   " << god.description << "\n";
        std::cout << "Meaning:       " << god.meaning << "\n";
        std::cout << "\n";
    }
}

void printHelp(const char* prog) {
    std::cout << "Usage: " << prog << " [options]\n\n"
              << "Options:\n"
              << "  -l, --list          List all Names of God with details\n"
              << "  -f, --filter <str>  List only names matching <str> (case-insensitive)\n"
              << "  -c, --count         Show the count of Names of God\n"
              << "  -v, --version       Show version\n"
              << "  -h, --help          Show this help message\n\n"
              << "If --list and --count are both given, the list is shown first.\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printHelp(argv[0]);
        return 0;
    }

    bool doList = false;
    bool doCount = false;
    std::string filter;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-l" || arg == "--list")         doList = true;
        else if (arg == "-c" || arg == "--count")   doCount = true;
        else if (arg == "-h" || arg == "--help")    { printHelp(argv[0]); return 0; }
        else if (arg == "-v" || arg == "--version") { std::cout << "namesofGod version " << VERSION << "\n"; return 0; }
        else if (arg == "-f" || arg == "--filter") {
            if (++i >= argc) {
                std::cerr << "--filter requires an argument\n";
                return 1;
            }
            filter = argv[i];
            doList = true;
        }
        else {
            std::cerr << "Unknown option: " << arg << "\n";
            printHelp(argv[0]);
            return 1;
        }
    }

    if (doList)  printList(filter);
    if (doCount) {
        size_t count = namesOfGod.size();
        if (!filter.empty()) {
            const std::string needle = toLower(filter);
            count = 0;
            for (const auto& god : namesOfGod)
                if (toLower(god.name).find(needle) != std::string::npos)
                    ++count;
        }
        std::cout << "Names of God: " << count << "\n";
    }

    return 0;
}
