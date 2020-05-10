#pragma once

#include <openvr.h>
#include <iostream>
#include <string>
#include <easylogging++.h>
#include <utility>

/* Wrapper For OpenVR's IVR settings class, allows us to do our error logging
 * while also minimizing code
 *
 */
namespace ovr_settings_wrapper
{
// might make sense to mirror ovr's errors exactly, but for now this is more
// than sufficient
enum class SettingsError
{
    NoError,
    UndefinedError,

};

std::pair<SettingsError, bool> getBool( std::string section,
                                        std::string settingsKey,
                                        std::string customErrorMsg = "" );

std::pair<SettingsError, int> getInt32( std::string section,
                                        std::string settingsKey,
                                        std::string customErrorMsg = "" );

std::pair<SettingsError, float> getFloat( std::string section,
                                          std::string settingsKey,
                                          std::string customErrorMsg = "" );
// TODO string

SettingsError setBool( std::string section,
                       std::string settingsKey,
                       bool bValue,
                       std::string customErrorMsg = "" );
SettingsError setInt32( std::string section,
                        std::string settingsKey,
                        int nValue,
                        std::string customErrorMsg = "" );
SettingsError setFloat( std::string section,
                        std::string settingsKey,
                        float flValue,
                        std::string customErrorMsg = "" );

SettingsError removeSection( std::string section,
                             std::string customErrorMsg = "" );
SettingsError removeKeyInSection( std::string section,
                                  std::string settingsKey,
                                  std::string customErrorMsg = "" );

SettingsError handleErrors( std::string settingsKey,
                            vr::EVRSettingsError,
                            std::string customErrorMsg );
} // namespace ovr_settings_wrapper
