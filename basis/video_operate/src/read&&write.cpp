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
    namedWindow("视频播放",WINDOW_AUTOSIZE);
    double fps = cap.get(CAP_PROP_FPS);
    int delay = 1000/fps; // 计算每帧的延时，单位为毫秒
    int frameWideth = cap.get(CAP_PROP_FRAME_WIDTH);
    int frameHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
    // 使用兼容的编码器和格式组合
    int fourcc = VideoWriter::fourcc('M','P','4','V'); // 使用H.264编码
    VideoWriter writer("/home/guoanyi/视频/megumin_30fps.mp4",fourcc,fps,Size(frameWideth,frameHeight),true);
    if(!writer.isOpened()) {
        cout << "无法创建视频写入器" << endl;
        return -1;
    }

    int count_fps = 0;
    while(true)
    {
        Mat frame;
        bool readSuccess = cap.read(frame);
        if(!readSuccess)
        {
            cout << "视频播放完毕或读取失败" << endl;
            break;
        }
        imshow("视频播放",frame);
        // 按 'q' 键退出播放
        if(waitKey(delay) == 27)
        {
            break;
        }
        while(count_fps++ < 30)
        {
             writer.write(frame);
        }

    }
    
    // 释放资源
    cap.release();
    destroyAllWindows();
    return 0;
}