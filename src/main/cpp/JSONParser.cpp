#include "JSONParser.h"
/* most of this code was stolen from 
frc/trajectory/TrajectoryUtil.h */

// path is from the deploy folder
custom2498::JSONParser::JSONParser(std::string jsonInputPath)
{
    wpi::SmallString<64> deployDirectory;
    frc::filesystem::GetDeployDirectory(deployDirectory);
    wpi::sys::path::append(deployDirectory, jsonInputPath);

    // this is the most sus thing
    // like it definitely is just wrong lmao
    std::string copy = (deployDirectory.str()).str();
    path_ = &copy;
}

void custom2498::JSONParser::Parse(GUI gui)
{
    std::error_code error_code;
    wpi::SmallString<128> buf;
    wpi::StringRef pathStringRef = wpi::StringRef(*path_);
    wpi::raw_fd_istream input{pathStringRef, error_code};
    if (error_code) {
        throw std::runtime_error(("Cannot open file: " + pathStringRef).str());
    }
    wpi::json json;
    input >> json;
    // TODO: actually turn the json into all the different methods and such
}