#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("/home/guoanyi/newprogramme/learn_opencv/source/jojo.jpg");
    if(img.empty())
    {
        cout<<"read img failed!"<<endl;
        return -1;
    }
    namedWindow("jojo",WINDOW_NORMAL);
    imshow("jojo",img);
    int key = waitKey(0);
    char choice{};
    cout<<"是否要保存图片？(y/n)"<<endl;
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        string jpegPath = "/home/guoanyi/图片/jojo.jpg";
        string pngPath = "/home/guoanyi/图片/jojo.png";
        
        bool jpegsuscess = imwrite(jpegPath, img, {IMWRITE_JPEG_QUALITY, 95});
        bool pngsuscess = imwrite(pngPath, img, {IMWRITE_PNG_COMPRESSION, 3});
        
        if(jpegsuscess) {
            cout << "JPEG图片保存成功: " << jpegPath << endl;
        } else {
            cout << "JPEG图片保存失败!" << endl;
        }
        
        if(pngsuscess) {
            cout << "PNG图片保存成功: " << pngPath << endl;
        } else {
            cout << "PNG图片保存失败!" << endl;
        }
    }
    destroyAllWindows();
    return 0;
}