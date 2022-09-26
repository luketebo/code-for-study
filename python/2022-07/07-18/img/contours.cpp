#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
src = imread("1.jpg");
if (!src.data)
{
    cout << "Can not read this image" << endl;
    return -1;
}