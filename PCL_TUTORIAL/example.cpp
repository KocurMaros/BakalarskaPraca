#include <iostream>
#include <thread>

#include <pcl/console/parse.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/sac_model_sphere.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/segmentation/sac_segmentation.h>

using namespace std::chrono_literals;

pcl::visualization::PCLVisualizer::Ptr
simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  //viewer->addCoordinateSystem (1.0, "global");
  viewer->initCameraParameters ();
  return (viewer);
}

int
main(int argc, char** argv)
{
  // initialize PointClouds
  // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr final (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
 
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *cloud) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }
  // populate our PointCloud with points
  // cloud->width    = 500;
  // cloud->height   = 1;
  // cloud->is_dense = false;
  // cloud->points.resize (cloud->width * cloud->height);
  // for (pcl::index_t i = 0; i < cloud->size (); ++i)
  // {
  //   if (pcl::console::find_argument (argc, argv, "-s") >= 0 || pcl::console::find_argument (argc, argv, "-sf") >= 0)
  //   {
  //     (*cloud)[i].x = 1024 * rand () / (RAND_MAX + 1.0);
  //     (*cloud)[i].y = 1024 * rand () / (RAND_MAX + 1.0);
  //     if (i % 5 == 0)
  //       (*cloud)[i].z = 1024 * rand () / (RAND_MAX + 1.0);
  //     else if(i % 2 == 0)
  //       (*cloud)[i].z =  sqrt( 1 - ((*cloud)[i].x * (*cloud)[i].x)
  //                                     - ((*cloud)[i].y * (*cloud)[i].y));
  //     else
  //       (*cloud)[i].z =  - sqrt( 1 - ((*cloud)[i].x * (*cloud)[i].x)
  //                                       - ((*cloud)[i].y * (*cloud)[i].y));
  //   }
  //   else
  //   {
  //     (*cloud)[i].x = 1024 * rand () / (RAND_MAX + 1.0);
  //     (*cloud)[i].y = 1024 * rand () / (RAND_MAX + 1.0);
  //     if( i % 2 == 0)
  //       (*cloud)[i].z = 1024 * rand () / (RAND_MAX + 1.0);
  //     else
  //       (*cloud)[i].z = -1 * ((*cloud)[i].x + (*cloud)[i].y);
  //   }
  // }

  std::vector<int> inliers;

  // created RandomSampleConsensus object and compute the appropriated model
  pcl::SampleConsensusModelSphere<pcl::PointXYZ>::Ptr
    model_s(new pcl::SampleConsensusModelSphere<pcl::PointXYZ> (cloud));
  pcl::SampleConsensusModelPlane<pcl::PointXYZ>::Ptr
    model_p (new pcl::SampleConsensusModelPlane<pcl::PointXYZ> (cloud));
  if(pcl::console::find_argument (argc, argv, "-f") >= 0)
  {
    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_p);
    ransac.setDistanceThreshold (.01);
    ransac.computeModel();
    ransac.getInliers(inliers);
  }
  else if (pcl::console::find_argument (argc, argv, "-sf") >= 0 )
  {
    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_s);
    ransac.setDistanceThreshold (.01);
    ransac.computeModel();
    ransac.getInliers(inliers);
  }

  // copies all inliers of the model computed to another PointCloud
  pcl::copyPointCloud (*cloud, inliers, *final);

  // creates the visualization object and adds either our original cloud or all of the inliers
  // depending on the command line arguments specified.
  pcl::visualization::PCLVisualizer::Ptr viewer;
  if (pcl::console::find_argument (argc, argv, "-f") >= 0 || pcl::console::find_argument (argc, argv, "-sf") >= 0)
    viewer = simpleVis(final);
  else
    viewer = simpleVis(cloud);
  viewer->spin();


  pcl::SACSegmentationFromNormals<pcl::PointXYZRGBNormal, pcl::PointXYZRGBNormal> seg;
  //vyratat normaly 
  //rozbehat kinect 
  //napajanie kinectu
  //teoria zaciatok
  //URK stiahniut template 
  //odkazy k zdrojom 
  seg.setOptimizeCoefficients(true);
  seg.setModelType(pcl::SACMODEL_SPHERE);
  seg.setMethodType(pcl::SAC_RANSAC);
  seg.setMaxIterations(500000);       
  seg.setDistanceThreshold(0.0020);    
  seg.setProbability(0.99900); 
  seg.setRadiusLimits(0.06, 0.08);
  seg.setInputCloud(cloud);
  scanMesh->populatePointCloud();

  // boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGBNormal> > cloud(scanMesh->cloud);

  // pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
  // segmentation.setInputCloud(cloud);
  // segmentation.setInputNormals(cloud);
  // segmentation.setModelType(pcl::SACMODEL_NORMAL_SPHERE);
  // segmentation.setMethodType(pcl::SAC_RANSAC);
  // segmentation.setDistanceThreshold(0.01); 
  // segmentation.setOptimizeCoefficients(true);
  // segmentation.setRadiusLimits(0.1, 0.15);
  // segmentation.setEpsAngle(15 / (180/3.141592654));
  // segmentation.setMaxIterations(1000000);

  // pcl::PointIndices inlierIndices;
  // segmentation.segment(inlierIndices, *coefficients);

  // if (inlierIndices.indices.size() == 0)
  //   printf("RANSAC nothing found");
  // else
  // {
  //   printf("RANSAC found shape with [%d] points", (int)inlierIndices.indices.size());
  //   for (int c=0; c<coefficients->values.size(); ++c)
  //       printf("Coeff %d = [%f]", (int)c+1, (float)coefficients->values[c]);

  //   // mark the found inliers in green
  //   for (int m=0; m<inlierIndices.indices.size(); ++m)
  //   {
  //       cloud->points[inlierIndices.indices[m]].r = 0;
  //       cloud->points[inlierIndices.indices[m]].g = 255;
  //       cloud->points[inlierIndices.indices[m]].b = 0;
  //   }
  // }
  


  // while (!viewer->wasStopped ())
  // {
  //   viewer->spinOnce (100);
  //   std::this_thread::sleep_for(100ms);
  // }
  return 0;
 }