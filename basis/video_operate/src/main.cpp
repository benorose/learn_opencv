#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 从视频文件读取
    VideoCapture cap("/home/guoanyi/newprogramme/learn_opencv/source/megumin.mp4");
    
    // 从摄像头读取（0表示默认摄像头）
    // VideoCapture cap(0);
    
    // 检查视频是否打开成功
    if (!cap.isOpened()) {
        cout << "无法打开视频文件或摄像头" << endl;
        return -1;
    }
    
    // 获取视频属性
    int frameWidth = cap.get(CAP_PROP_FRAME_WIDTH);    // 帧宽度
    int frameHeight = cap.get(CAP_PROP_FRAME_HEIGHT);  // 帧高度
    double fps = cap.get(CAP_PROP_FPS);                // 帧率
    int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);   // 总帧数
    
    cout << "视频宽度: " << frameWidth << endl;
    cout << "视频高度: " << frameHeight << endl;
    cout << "帧率: " << fps << endl;
    cout << "总帧数: " << totalFrames << endl;
    
    // 读取一帧视频
    Mat frame;
    cap.read(frame);
    
    if (frame.empty()) {
        cout << "无法读取视频帧" << endl;
        return -1;
    }
    
    // 释放资源
    cap.release();
    
    return 0;
}