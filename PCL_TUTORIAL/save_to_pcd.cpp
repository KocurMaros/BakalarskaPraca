#include <iostream>
#include <string>
#include <sstream>
#include <functional>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/openni2_grabber.h>

#include <pcl/visualization/cloud_viewer.h>

using namespace std; 
// using namespace placeholders;

const string OUT_DIR = "/home/laptop/BakalarskaPraca/PCL_TUTORIAL/build/pcd/"; 

//export LIBVA_DRIVER_NAME=i965

class SimpleOpenNIViewer 
{ 
public: 
    SimpleOpenNIViewer () : viewer ("PCL Viewer") 
    { 
                frames_saved = 0; 
                save_one = false; 
    } 

    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud) 
    { 
                if (!viewer.wasStopped()) { 
                        viewer.showCloud (cloud); 
                        if( save_one ) { 
                                save_one = false; 
                                std::stringstream out; 
                                out << frames_saved; 
                                std::string name = OUT_DIR + "kinect_pcd" + out.str() + ".pcd"; 
                                pcl::io::savePCDFileASCII( name, *cloud ); 
                        } 
                } 
    } 

    void run () 
    { 
                pcl::Grabber* interface = new pcl::io::OpenNI2Grabber(); 

                // boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f = 
                //         boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, boost::placeholders::_1); 

                std::function<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f = 
                        boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, boost::placeholders::_1); 
                interface->registerCallback (f); 

                interface->start (); 

                char c; 
                
                while (!viewer.wasStopped())  
                { 
                        //sleep (1); 

                        c = getchar(); 
                        if( c == 's' ) { 
                                cout << "Saving frame " << frames_saved << ".\n"; 
                                frames_saved++; 
                                save_one = true; 
                        } 
                } 

                interface->stop (); 
        } 

        pcl::visualization::CloudViewer viewer; 

        private: 
                int frames_saved; 
                bool save_one; 

}; 

int main () 
{ 
    SimpleOpenNIViewer v; 
    v.run (); 
    return 0; 
} 