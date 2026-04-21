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
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

struct NameOfGod {
    std::string name;
    std::string pronunciation;
    std::string description;
    std::string meaning;
    std::vector<std::string> references;
};

const std::array<NameOfGod, 19> namesOfGod = {{
    {
        "El, Eloah",
        "el, el-oh-ah",
        "Mighty, Strong, Prominent",
        "Root meaning is power and might.",
        {"Nehemiah 9:17", "Psalm 139:19", "Genesis 31:29", "Numbers 23:19", "Deuteronomy 5:9", "Nehemiah 9:31"}
    },
    {
        "Elohim",
        "el-oh-heem",
        "Creator, Mighty and Strong",
        "Plural form reflecting the nature of the Trinity.",
        {"Genesis 1:1", "Genesis 17:7", "Jeremiah 31:33"}
    },
    {
        "El Shaddai",
        "el-shah-dahy",
        "God Almighty, The Mighty One of Jacob",
        "Speaks to ultimate divine power.",
        {"Genesis 17:1", "Exodus 6:3", "Ruth 1:20"}
    },
    {
        "Adonai",
        "ah-daw-nahy",
        "Lord, Master",
        "Emphasizes an authoritative relationship and reverence.",
        {"Genesis 15:2", "Judges 6:15"}
    },
    {
        "YHWH / Yahweh / Jehovah",
        "yah-way / ji-hoh-veh",
        "LORD",
        "The personal, proper name of God. I AM WHO I AM. Denotes his eternal presence and accessibility.",
        {"Exodus 3:14", "Exodus 3:15", "Deuteronomy 6:4", "Daniel 9:14"}
    },
    {
        "Yahweh-Jireh",
        "yah-way-ji-reh",
        "The Lord Will Provide",
        "Memorialized when God provided a ram as sacrifice in place of Isaac.",
        {"Genesis 22:14"}
    },
    {
        "Yahweh-Rapha",
        "yah-way-rah-fah",
        "The Lord Who Heals",
        "Healing of body and soul.",
        {"Exodus 15:26"}
    },
    {
        "Yahweh-Nissi",
        "yah-way-nee-see",
        "The Lord Our Banner",
        "A rallying place; commemorates God's victory over the Amalekites.",
        {"Exodus 17:15"}
    },
    {
        "Yahweh-M'Kaddesh",
        "yah-way-meh-kad-esh",
        "The Lord Who Sanctifies, Makes Holy",
        "Only God cleanses and sets apart his people.",
        {"Leviticus 20:8", "Ezekiel 37:28"}
    },
    {
        "Yahweh-Shalom",
        "yah-way-shah-lohm",
        "The Lord Our Peace",
        "Name given by Gideon to the altar he built after God's reassurance.",
        {"Judges 6:24"}
    },
    {
        "Yahweh-Elohim",
        "yah-way-el-oh-him",
        "LORD God",
        "Combination name denoting his unique identity as both personal Lord and almighty God.",
        {"Genesis 2:4", "Psalm 59:5"}
    },
    {
        "Yahweh-Tsidkenu",
        "yah-way-tzid-kay-noo",
        "The Lord Our Righteousness",
        "Only God provides the righteousness required to stand before him.",
        {"Jeremiah 33:16", "2 Corinthians 5:21"}
    },
    {
        "Yahweh-Rohi",
        "yah-way-roh-hee",
        "The Lord Our Shepherd",
        "Drawn from David's own experience as a shepherd.",
        {"Psalm 23:1"}
    },
    {
        "Yahweh-Shammah",
        "yah-way-sham-mahw",
        "The Lord Is There",
        "Indicates the return of God's glory to Jerusalem in the age to come.",
        {"Ezekiel 48:35"}
    },
    {
        "Yahweh-Sabaoth",
        "yah-way-sah-bah-ohth",
        "The Lord of Hosts",
        "Lord over all angels and humanity. Expresses supreme majesty and authority.",
        {"Isaiah 1:24", "Psalm 46:7"}
    },
    {
        "El Elyon",
        "el-el-yohn",
        "Most High",
        "Denotes his exaltation and absolute sovereignty over all.",
        {"Genesis 14:18-22", "Deuteronomy 32:8", "Psalm 7:17", "Psalm 57:2", "Psalm 97:9"}
    },
    {
        "El Roi",
        "el-roh-ee",
        "God of Seeing",
        "The God who perceives our distress and sees all things. Named by Hagar.",
        {"Genesis 16:13"}
    },
    {
        "El Olam",
        "el-oh-lahm",
        "Everlasting God",
        "Eternal, existing outside and beyond the constraints of time.",
        {"Psalm 90:1-3"}
    },
    {
        "El Gibhor",
        "el-ghee-bohr",
        "Mighty God",
        "Describes the Messiah as a powerful warrior who defeats his enemies.",
        {"Isaiah 9:6", "Revelation 19:15"}
    }
}};

static bool bvAvailable() {
    return std::system("which bv >/dev/null 2>&1") == 0;
}

static void callBv(const NameOfGod& god) {
    for (const auto& ref : god.references) {
        std::string cmd = "bv --ref=\"" + ref + "\"";
        std::system(cmd.c_str());
    }
}

static std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(), ::tolower);
    return out;
}

void printOne(const NameOfGod& god, bool showRef = false) {
    std::cout << "Name:          " << god.name << "\n";
    std::cout << "Pronunciation: " << god.pronunciation << "\n";
    std::cout << "Description:   " << god.description << "\n";
    std::cout << "Meaning:       " << god.meaning << "\n";
    std::cout << "References:    ";
    for (size_t i = 0; i < god.references.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << god.references[i];
    }
    std::cout << "\n";
    if (showRef) {
        if (bvAvailable())
            callBv(god);
        else
            std::cerr << "(bv not found on PATH — install bv to view verses)\n";
    }
}

void printList(const std::string& filter = "", bool showRef = false) {
    const std::string needle = toLower(filter);
    for (const auto& god : namesOfGod) {
        if (!needle.empty() && toLower(god.name).find(needle) == std::string::npos)
            continue;
        printOne(god, showRef);
        std::cout << "\n";
    }
}

void pickRandom(bool showRef = false) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    printOne(namesOfGod[std::rand() % namesOfGod.size()], showRef);
}

void printHelp(const char* prog) {
    std::cout << "Usage: " << prog << " [options]\n\n"
              << "Options:\n"
              << "  -p, --pick          Pick and print one Name of God at random (default)\n"
              << "  -l, --list          List all Names of God with details\n"
              << "  -sr, --showref      Call bv for each reference after printing (if bv is on PATH)\n"
              << "  -f, --filter <str>  List only names matching <str> (case-insensitive)\n"
              << "  -c, --count         Show the count of Names of God\n"
              << "  -v, --version       Show version\n"
              << "  -h, --help          Show this help message\n\n"
              << "If --list and --count are both given, the list is shown first.\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        pickRandom();
        return 0;
    }

    bool doPick = false;
    bool doList = false;
    bool doCount = false;
    bool doShowRef = false;
    std::string filter;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-p" || arg == "--pick")           doPick = true;
        else if (arg == "-l" || arg == "--list")      doList = true;
        else if (arg == "-c" || arg == "--count")     doCount = true;
        else if (arg == "-sr" || arg == "--showref")  doShowRef = true;
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

    if (!doPick && !doList && doShowRef) doPick = true;

    if (doPick)  pickRandom(doShowRef);
    if (doList)  printList(filter, doShowRef);
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
