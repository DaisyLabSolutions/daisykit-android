#pragma once

#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

#include <android/asset_manager_jni.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <jni.h>

#include <opencv2/opencv.hpp>

#include "asset_mgr_utils.h"
#include "thirdparties/ndkcamera/ndkcamera.h"

#include <daisykitsdk/common/types.h>
#include <daisykitsdk/flows/pushup_counter_flow.h>

static int draw_unsupported(cv::Mat& rgb) {
  const char text[] = "unsupported";

  int baseLine = 0;
  cv::Size label_size =
      cv::getTextSize(text, cv::FONT_HERSHEY_SIMPLEX, 1.0, 1, &baseLine);

  int y = (rgb.rows - label_size.height) / 2;
  int x = (rgb.cols - label_size.width) / 2;

  cv::rectangle(
      rgb,
      cv::Rect(cv::Point(x, y),
               cv::Size(label_size.width, label_size.height + baseLine)),
      cv::Scalar(255, 255, 255), -1);

  cv::putText(rgb, text, cv::Point(x, y + label_size.height),
              cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 0, 0));

  return 0;
}
