#pragma once

#include <string>
#include <unordered_map>

struct Input
{
  Input();

  // fixed data
  //
  bool noWindow;
  bool exitStatus;
  bool enableOpenGL1;
  bool enableMLT;
  bool allocInternalImageB;
  bool runTests;     ///< run all functional tests from HydraAPI folder 
  bool listDevicesAndExit;
  bool cpuFB;
  bool inDevelopment;
  bool getGBufferBeforeRender;

  std::string   inLibraryPath;
  std::string   outLDRImage;
  std::string   inLogDirCust;
  std::string   inSharedImageName;

  std::wstring  inTestsFolder;

  int32_t     inSeed;
  int32_t     inDeviceId;
  int32_t     winWidth;
  int32_t     winHeight;

  // mouse and keyboad/oher gui input
  //
  float camMoveSpeed;
  float mouseSensitivity;
  float saveInterval;

  // dynamic data
  //

  bool pathTracingEnabled;
  bool lightTracingEnabled;
  bool ibptEnabled;
  bool cameraFreeze;

  void ParseCommandLineParams(const std::unordered_map<std::string, std::string>& a_params);
};
