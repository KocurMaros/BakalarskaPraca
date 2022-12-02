#include <boost/thread/thread.hpp>
#include <pcl/visualization/cloud_viewer.h>

#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>

#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/pcl_visualizer.h>
/** pthread_mutex_t cpp wrapper */
/*
class Mutex
{
public:
    Mutex() { pthread_mutex_init(&m_mutex, NULL); }
    void lock() { pthread_mutex_lock(&m_mutex); }
    void unlock() { pthread_mutex_unlock(&m_mutex); }

    class ScopedLock
    {
    public:
        ScopedLock(Mutex &mutex) : _mutex(mutex) { _mutex.lock(); }
        ~ScopedLock() { _mutex.unlock(); }
    private:
        Mutex &_mutex;
    };
private:
    pthread_mutex_t m_mutex;
};

// class to handle the drawing and openni callbacks 
class SimpleOpenNIViewer
{
public:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    Mutex * mutex;

    SimpleOpenNIViewer():
        viewer(new pcl::visualization::PCLVisualizer ("3D Viewer")),
        mutex(new Mutex)
    {}

    //  OpenNI callback. Each time a data pack arrives, the Mutex is locked,
    //    and the cloud is updated.
    
    void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
    {
        mutex->lock();
        viewer->updatePointCloud(cloud, "kinect_cloud");
        mutex->unlock();
    }

    void run ()
    {
        // Start off by creating an empty point cloud (with support for depth (XYZ) and color (RGBA)))
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr kinect_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGBA>);
        // Add the empt cloud to the viewer. The cloud will be updated with every openni callback
        viewer->addPointCloud<pcl::PointXYZRGBA> (kinect_cloud_ptr, "kinect_cloud");
        viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "kinect_cloud");
        // Create the openni interface, and set cloud_cb_ as the callback
        pcl::Grabber* interface = new pcl::OpenNIGrabber();
        boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f =
                boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);
        // Start the interface
        interface->registerCallback (f);
        interface->start ();

        while (!viewer->wasStopped())
        {   
            // Aquire the mutex, to make sure that the cloud isn't being updated
            mutex->lock();
            // Redraw cloud
            viewer->spinOnce (20);
            // Release mutex
            mutex->unlock();
        }
        interface->stop ();
    }
};
*/
// class SimpleOpenNIProcessor
// {
// public:
//     pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2;
//      SimpleOpenNIProcessor () : viewer ("PCL OpenNI Viewer") {}
//      void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
//   {

//     *(cloud2)=*(cloud);
//      if (!viewer.wasStopped())
//          viewer.showCloud (cloud);

//   }

//   void run ()
//   {

//     // create a new grabber for OpenNI devices
//     pcl::Grabber* interface = new pcl::OpenNIGrabber();

//     // make callback function from member function
//     boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f =
//       boost::bind (&SimpleOpenNIProcessor::cloud_cb_, this, std::placeholders::_1);

//     // connect callback function for desired signal. In this case its a point cloud with color values
//     boost::signals2::connection c = interface->registerCallback (f);

//     // start receiving point clouds
//     interface->start ();

//     // wait until user quits program with Ctrl-C, but no busy-waiting -> sleep (1);
//     while (true)
//       sleep(1);

//     // stop the grabber
//     interface->stop ();
//   }
//       pcl::visualization::CloudViewer viewer;

// };

// int main ()
// {

//   SimpleOpenNIProcessor v;
//   v.run ();
//   return (0);
// }
// int main ()
// {
//     SimpleOpenNIViewer v;
//     v.run ();
//     return 0;
// }
#include <thread>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/common/time.h>

using namespace std::chrono_literals;

class SimpleOpenNIProcessor
{
public:
  void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr &cloud)
  {
    static unsigned count = 0;
    static double last = pcl::getTime ();
    if (++count == 30)
    {
      double now = pcl::getTime ();
      std::cout << "distance of center pixel :" << cloud->points [(cloud->width >> 1) * (cloud->height + 1)].z << " mm. Average framerate: " << double(count)/double(now - last) << " Hz" <<  std::endl;
      count = 0;
      last = now;
    }
  }
  
  void run ()
  {
    // create a new grabber for OpenNI devices
    pcl::Grabber* interface = new pcl::OpenNIGrabber();

    // make callback function from member function
    std::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> f =
      [this] (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& cloud) { cloud_cb_ (cloud); };

    // connect callback function for desired signal. In this case its a point cloud with color values
    boost::signals2::connection c = interface->registerCallback (f);

    // start receiving point clouds
    interface->start ();

    // wait until user quits program with Ctrl-C, but no busy-waiting -> sleep (1);
    while (true)
      std::this_thread::sleep_for(1s);

    // stop the grabber
    interface->stop ();
  }
};

int main ()
{
  SimpleOpenNIProcessor v;
  v.run ();
  return (0);
}