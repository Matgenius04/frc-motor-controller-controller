#include "wpi/json.h"
#include <wpi/raw_istream.h>
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <system_error>
#include <wpi/Path.h>
#include <wpi/SmallString.h>
#include <string>
#include "GUI.h"

namespace custom2498
{
    class JSONParser
    {
    public:
        // creates a json parser for a specific json file
        JSONParser(std::string path);
        // reads the json from the path and then
        // adds all the correct info to the gui
        // and creates the mecanum drive base
        void Parse(GUI gui);

    private:
        const std::string* path_;
    };
} // namespace custom2498