 #include <iostream>
 #include <pcl/io/pcd_io.h>
 #include <pcl/io/pcd_io.h>
 #include <pcl/point_types.h>
 #include <pcl/visualization/cloud_viewer.h>
#include <boost/filesystem/path.hpp>

 int main ()
 {
   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
 
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }

  pcl::visualization::PCLVisualizer axes;
  // axes.addCoordinateSystem(1.0,0);
  axes.addPointCloud(cloud);
  axes.spin();
  // while (!axes.wasStopped()){
  //   axes.spinOnce(100);
  //   boost::this_thread::sleep(boost::posix_time::microseconds(100000));
  // }
  // pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
  // viewer.showCloud (cloud);
  // while (!viewer.wasStopped ())
  // {
  // }  


  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from test_pcd.pcd with the following fields: "
            << std::endl;
  for (const auto& point: *cloud)
    std::cout << "    " << point.x
              << " "    << point.y
              << " "    << point.z << std::endl;

  return (0);
}
