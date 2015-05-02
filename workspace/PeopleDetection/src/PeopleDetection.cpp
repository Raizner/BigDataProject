



        #include <iostream>
        #include <opencv2/opencv.hpp>
        #include <stdio.h>
        #include <string>     // std::string, std::to_string


        using namespace std;
        using namespace cv;

        int main (int argc, const char * argv[])
        {
            VideoCapture cap(1);
            /*
            cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
            cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
                */
            if (!cap.isOpened())
                return -1;

            Mat img;


          VideoCapture cap1(2);

            //cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
            //cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

            if (!cap1.isOpened())
                return -1;

            Mat img1;

            string Pos = "";
            HOGDescriptor hog;
            hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
            //string posPoint = "";
            string posRect ="";
            string posRect2 ="";
            bool onceOnly = true;
            while (true)
            {
                cap >> img;
               cap1 >> img1;



               Mat tempFrame = img;
               Mat tempFrame1 = img1;

               cv::transpose(img, tempFrame);
               cv::flip(tempFrame, tempFrame, 0);

               cv::transpose(tempFrame, img);
               cv::flip(img, img, 0);

               cv::transpose(img1, tempFrame1);
               cv::flip(tempFrame1, tempFrame1, 0);

               cv::transpose(tempFrame1, img1);
               cv::flip(img1, img1, 0);



                if (!img.data)
                    continue;

                vector<Rect> found, found_filtered;
                vector<Rect> found1, found_filtered1;
                hog.detectMultiScale(img, found, 0, Size(8,8), Size(32,32), 1.05, 2);
                hog.detectMultiScale(img1, found1, 0, Size(8,8), Size(32,32), 1.05, 2);
                //hog.detect(img, found1, 0, Size(8,8), Size(0,0));

                size_t i, j;



                for (i=0; i<found.size(); i++)
                {
                    Rect r = found[i];
                    for (j=0; j<found.size(); j++)
                        if (j!=i && (r & found[j])==r)
                            break;
                    if (j==found.size())
                        found_filtered.push_back(r);
                }
                for (i=0; i<found_filtered.size(); i++)
                {
                    Rect r = found_filtered[i];
                    r.x += cvRound(r.width*0.1);
                    r.width = cvRound(r.width*0.8);
                    r.y += cvRound(r.height*0.06);
                    r.height = cvRound(r.height*0.9);

                    string x = to_string(r.x);
                    string y = to_string(r.y);
                    posRect = "Pos: x:" + x+ " y: " + y;

                    rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                }




                for (i=0; i<found1.size(); i++)
                {
                    Rect r = found1[i];
                    for (j=0; j<found1.size(); j++)
                        if (j!=i && (r & found1[j])==r)
                            break;
                    if (j==found1.size())
                        found_filtered1.push_back(r);
                }
                for (i=0; i<found_filtered1.size(); i++)
                {
                    Rect r = found_filtered1[i];
                    r.x += cvRound(r.width*0.1);
                    r.width = cvRound(r.width*0.8);
                    r.y += cvRound(r.height*0.06);
                    r.height = cvRound(r.height*0.9);

                    string x = to_string(r.x);
                    string y = to_string(r.y);
                    posRect2 = "Pos: x:" + x+ " y: " + y;

                    rectangle(img1, r.tl(), r.br(), cv::Scalar(0,255,0), 2);
                }


                int number  = 5;
                char text[255];
                sprintf(text, "Score %d", (int)number);

                CvFont font;
                double hScale=1.0;
                double vScale=1.0;
                int    lineWidth=1;
                cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);

                IplImage* img00 = new IplImage(img);
                IplImage* img11 = new IplImage(img1);

                char* p = new char[posRect.length()+1];

                memcpy(p, posRect.c_str(), posRect.length()+1);

                cvPutText(img00, p, cvPoint(200,400), &font, cvScalar(0,255,0));

                char* p2 = new char[posRect2.length()+1];
                memcpy(p2, posRect2.c_str(), posRect2.length()+1);
                cvPutText(img11, p2, cvPoint(200,300), &font, cvScalar(255,255,255));




                imshow("video capture", img);
                imshow("video capture2", img1);

                if (waitKey(1) >= 0)
                    break;

            }

            namedWindow("video capture", CV_WINDOW_AUTOSIZE);

            return 0;
        }

