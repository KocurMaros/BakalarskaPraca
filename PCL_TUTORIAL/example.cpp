#include <pcl/io/openni2_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <boost/thread.hpp>
// #include <thread>
// #include <chrono>
// using namespace std::chrono_literals;
class SimpleOpenNIViewer
{
    public:
        SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}
        void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
        {
        
        if (!viewer.wasStopped())
            viewer.showCloud (cloud);
        }
        void run ()
        {

            pcl::Grabber* interface = new pcl::io::OpenNI2Grabber();
            std::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f =
                [this] (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud) { cloud_cb_ (cloud);};
            
            interface->registerCallback (f);
            interface->start ();
            // boost::this_thread::sleep (boost::posix_time::seconds (1));

            while (!viewer.wasStopped())
            {
                boost::this_thread::sleep (boost::posix_time::seconds (1));
            }
            interface->stop ();
        }
        pcl::visualization::CloudViewer viewer;
};
int main ()
{
  SimpleOpenNIViewer v;
  v.run ();
  return 0;
}