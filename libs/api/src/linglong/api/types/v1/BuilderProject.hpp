// This file is generated by tools/codegen.sh
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     BuilderProject.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "linglong/api/types/v1/helper.hpp"

#include "linglong/api/types/v1/BuilderProjectPackage.hpp"
#include "linglong/api/types/v1/ApplicationConfigurationPermissions.hpp"
#include "linglong/api/types/v1/BuilderProjectSource.hpp"

namespace linglong {
namespace api {
namespace types {
namespace v1 {
/**
* Linglong project build file.
*/

using nlohmann::json;

/**
* Linglong project build file.
*/
struct BuilderProject {
/**
* used base of package
*/
std::string base;
/**
* build script of builder project
*/
std::string build;
/**
* command of builder project
*/
std::optional<std::vector<std::string>> command;
/**
* Specify how to split application into modules.
*/
std::optional<std::map<std::string, std::vector<std::string>>> modules;
/**
* package of build file
*/
BuilderProjectPackage package;
std::optional<ApplicationConfigurationPermissions> permissions;
/**
* used runtime of package
*/
std::optional<std::string> runtime;
/**
* sources of package
*/
std::optional<std::vector<BuilderProjectSource>> sources;
/**
* strip script of builder project
*/
std::optional<std::string> strip;
/**
* version of build file
*/
std::string version;
};
}
}
}
}

// clang-format on
