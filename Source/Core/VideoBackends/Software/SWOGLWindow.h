// Copyright 2015 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Common/CommonTypes.h"
#include "VideoCommon/VideoCommon.h"

class AbstractTexture;

class SWOGLWindow
{
public:
  static void Init(void* window_handle);
  static void Shutdown();
  void Prepare();

  // Image to show, will be swapped immediately
  void ShowImage(AbstractTexture* image, const EFBRectangle& xfb_region);

  int PeekMessages();

  static std::unique_ptr<SWOGLWindow> s_instance;

private:
  SWOGLWindow() {}

  bool m_init{false};

  u32 m_image_program, m_image_texture, m_image_vao;
};
