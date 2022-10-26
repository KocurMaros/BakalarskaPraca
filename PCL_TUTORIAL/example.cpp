// #include <iostream>
// #include <thread>

// #include <pcl/console/parse.h>
// #include <pcl/filters/extract_indices.h>
// #include <pcl/io/pcd_io.h>
// #include <pcl/point_types.h>
// #include <pcl/sample_consensus/ransac.h>
// #include <pcl/sample_consensus/sac_model_plane.h>
// #include <pcl/sample_consensus/sac_model_sphere.h>
// #include <pcl/visualization/pcl_visualizer.h>
// #include <pcl/segmentation/sac_segmentation.h>

// using namespace std::chrono_literals;

// pcl::visualization::PCLVisualizer::Ptr
// simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
// {
//   // --------------------------------------------
//   // -----Open 3D viewer and add point cloud-----
//   // --------------------------------------------
//   pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
//   viewer->setBackgroundColor (0, 0, 0);
//   viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
//   viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
//   //viewer->addCoordinateSystem (1.0, "global");
//   viewer->initCameraParameters ();
//   return (viewer);
// }

// int
// main(int argc, char** argv)
// {
//   // initialize PointClouds
//   // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
//   pcl::PointCloud<pcl::PointXYZRGB>::Ptr final (new pcl::PointCloud<pcl::PointXYZRGB>);
//   pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
 
//   if (pcl::io::loadPCDFile<pcl::PointXYZRGB> ("test_pcd.pcd", *cloud) == -1) //* load the file
//   {
//     PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
//     return (-1);
//   }
//   // populate our PointCloud with points
//   // cloud->width    = 500;
//   // cloud->height   = 1;
//   // cloud->is_dense = false;
//   // cloud->points.resize (cloud->width * cloud->height);
//   // for (pcl::index_t i = 0; i < cloud->size (); ++i)
//   // {
//   //   if (pcl::console::find_argument (argc, argv, "-s") >= 0 || pcl::console::find_argument (argc, argv, "-sf") >= 0)
//   //   {
//   //     (*cloud)[i].x = 1024 * rand () / (RAND_MAX + 1.0);
//   //     (*cloud)[i].y = 1024 * rand () / (RAND_MAX + 1.0);
//   //     if (i % 5 == 0)
//   //       (*cloud)[i].z = 1024 * rand () / (RAND_MAX + 1.0);
//   //     else if(i % 2 == 0)
//   //       (*cloud)[i].z =  sqrt( 1 - ((*cloud)[i].x * (*cloud)[i].x)
//   //                                     - ((*cloud)[i].y * (*cloud)[i].y));
//   //     else
//   //       (*cloud)[i].z =  - sqrt( 1 - ((*cloud)[i].x * (*cloud)[i].x)
//   //                                       - ((*cloud)[i].y * (*cloud)[i].y));
//   //   }
//   //   else
//   //   {
//   //     (*cloud)[i].x = 1024 * rand () / (RAND_MAX + 1.0);
//   //     (*cloud)[i].y = 1024 * rand () / (RAND_MAX + 1.0);
//   //     if( i % 2 == 0)
//   //       (*cloud)[i].z = 1024 * rand () / (RAND_MAX + 1.0);
//   //     else
//   //       (*cloud)[i].z = -1 * ((*cloud)[i].x + (*cloud)[i].y);
//   //   }
//   // }

//   // std::vector<int> inliers;

//   // // created RandomSampleConsensus object and compute the appropriated model
//   // pcl::SampleConsensusModelSphere<pcl::PointXYZRGB>::Ptr
//   //   model_s(new pcl::SampleConsensusModelSphere<pcl::PointXYZ> (cloud));
//   // pcl::SampleConsensusModelPlane<pcl::PointXYZRGB>::Ptr
//   //   model_p (new pcl::SampleConsensusModelPlane<pcl::PointXYZ> (cloud));
//   // if(pcl::console::find_argument (argc, argv, "-f") >= 0)
//   // {
//   //   pcl::RandomSampleConsensus<pcl::PointXYZRGB> ransac (model_p);
//   //   ransac.setDistanceThreshold (.01);
//   //   ransac.computeModel();
//   //   ransac.getInliers(inliers);
//   // }
//   // else if (pcl::console::find_argument (argc, argv, "-sf") >= 0 )
//   // {
//   //   pcl::RandomSampleConsensus<pcl::PointXYZRGB> ransac (model_s);
//   //   ransac.setDistanceThreshold (.01);
//   //   ransac.computeModel();
//   //   ransac.getInliers(inliers);
//   // }

//   // copies all inliers of the model computed to another PointCloud
//   // pcl::copyPointCloud (*cloud, inliers, *final);

//   pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
//   viewer->setBackgroundColor (0, 0, 0);
//   pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
//   viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
//   viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
//   // viewer->addCoordinateSystem (1.0);
//   viewer->initCameraParameters ();
//   viewer->spin();

//   // // creates the visualization object and adds either our original cloud or all of the inliers
//   // // depending on the command line arguments specified.
//   // pcl::visualization::PCLVisualizer::Ptr viewer;
//   // // if (pcl::console::find_argument (argc, argv, "-f") >= 0 || pcl::console::find_argument (argc, argv, "-sf") >= 0)
//   // //   viewer = simpleVis(final);
//   // // else
//   //   viewer = simpleVis(cloud);
//   // viewer->spin();



//   pcl::SACSegmentationFromNormals<pcl::PointXYZRGBNormal, pcl::PointXYZRGBNormal> seg;
//   //vyratat normaly 
//   //rozbehat kinect 
//   //napajanie kinectu
//   //teoria zaciatok
//   //URK stiahniut template 
//   //odkazy k zdrojom 
//   // seg.setOptimizeCoefficients(true);
//   // seg.setModelType(pcl::SACMODEL_SPHERE);
//   // seg.setMethodType(pcl::SAC_RANSAC);
//   // seg.setMaxIterations(500000);       
//   // seg.setDistanceThreshold(0.0020);    
//   // seg.setProbability(0.99900); 
//   // seg.setRadiusLimits(0.06, 0.08);
//   // seg.setInputCloud(cloud);
//   // scanMesh->populatePointCloud();

//   // boost::shared_ptr<pcl::PointCloud<pcl::PointXYZRGBNormal> > cloud(scanMesh->cloud);

//   // pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
//   // segmentation.setInputCloud(cloud);
//   // segmentation.setInputNormals(cloud);
//   // segmentation.setModelType(pcl::SACMODEL_NORMAL_SPHERE);
//   // segmentation.setMethodType(pcl::SAC_RANSAC);
//   // segmentation.setDistanceThreshold(0.01); 
//   // segmentation.setOptimizeCoefficients(true);
//   // segmentation.setRadiusLimits(0.1, 0.15);
//   // segmentation.setEpsAngle(15 / (180/3.141592654));
//   // segmentation.setMaxIterations(1000000);

//   // pcl::PointIndices inlierIndices;
//   // segmentation.segment(inlierIndices, *coefficients);

//   // if (inlierIndices.indices.size() == 0)
//   //   printf("RANSAC nothing found");
//   // else
//   // {
//   //   printf("RANSAC found shape with [%d] points", (int)inlierIndices.indices.size());
//   //   for (int c=0; c<coefficients->values.size(); ++c)
//   //       printf("Coeff %d = [%f]", (int)c+1, (float)coefficients->values[c]);

//   //   // mark the found inliers in green
//   //   for (int m=0; m<inlierIndices.indices.size(); ++m)
//   //   {
//   //       cloud->points[inlierIndices.indices[m]].r = 0;
//   //       cloud->points[inlierIndices.indices[m]].g = 255;
//   //       cloud->points[inlierIndices.indices[m]].b = 0;
//   //   }
//   // }
  


//   // while (!viewer->wasStopped ())
//   // {
//   //   viewer->spinOnce (100);
//   //   std::this_thread::sleep_for(100ms);
//   // }
//   return 0;
//  }
/* \author Geoffrey Biggs */

#include <iostream>
#include <thread>

#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>

using namespace std::chrono_literals;

// --------------
// -----Help-----
// --------------
void
printUsage (const char* progName)
{
  std::cout << "\n\nUsage: "<<progName<<" [options]\n\n"
            << "Options:\n"
            << "-------------------------------------------\n"
            << "-h           this help\n"
            << "-s           Simple visualisation example\n"
            << "-r           RGB colour visualisation example\n"
            << "-c           Custom colour visualisation example\n"
            << "-n           Normals visualisation example\n"
            << "-a           Shapes visualisation example\n"
            << "-v           Viewports example\n"
            << "-i           Interaction Customization example\n"
            << "\n\n";
}


pcl::visualization::PCLVisualizer::Ptr simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr rgbVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr customColourVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 0, 255, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr normalsVis (
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud, pcl::PointCloud<pcl::Normal>::ConstPtr normals)
{
  // --------------------------------------------------------
  // -----Open 3D viewer and add point cloud and normals-----
  // --------------------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal> (cloud, normals, 10, 0.05, "normals");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr shapesVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();

  //------------------------------------
  //-----Add shapes at cloud points-----
  //------------------------------------
  viewer->addLine<pcl::PointXYZRGB> ((*cloud)[0],
                                     (*cloud)[cloud->size() - 1], "line");
  viewer->addSphere ((*cloud)[0], 0.2, 0.5, 0.5, 0.0, "sphere");

  //---------------------------------------
  //-----Add shapes at other locations-----
  //---------------------------------------
  pcl::ModelCoefficients coeffs;
  coeffs.values.push_back (0.0);
  coeffs.values.push_back (0.0);
  coeffs.values.push_back (1.0);
  coeffs.values.push_back (0.0);
  viewer->addPlane (coeffs, "plane");
  coeffs.values.clear ();
  coeffs.values.push_back (0.3);
  coeffs.values.push_back (0.3);
  coeffs.values.push_back (0.0);
  coeffs.values.push_back (0.0);
  coeffs.values.push_back (1.0);
  coeffs.values.push_back (0.0);
  coeffs.values.push_back (5.0);
  viewer->addCone (coeffs, "cone");

  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr viewportsVis (
    pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud, pcl::PointCloud<pcl::Normal>::ConstPtr normals1, pcl::PointCloud<pcl::Normal>::ConstPtr normals2)
{
  // --------------------------------------------------------
  // -----Open 3D viewer and add point cloud and normals-----
  // --------------------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->initCameraParameters ();

  int v1(0);
  viewer->createViewPort(0.0, 0.0, 0.5, 1.0, v1);
  viewer->setBackgroundColor (0, 0, 0, v1);
  viewer->addText("Radius: 0.01", 10, 10, "v1 text", v1);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud1", v1);

  int v2(0);
  viewer->createViewPort(0.5, 0.0, 1.0, 1.0, v2);
  viewer->setBackgroundColor (0.3, 0.3, 0.3, v2);
  viewer->addText("Radius: 0.1", 10, 10, "v2 text", v2);
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> single_color(cloud, 0, 255, 0);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, single_color, "sample cloud2", v2);

  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud1");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud2");
  viewer->addCoordinateSystem (1.0);

  viewer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal> (cloud, normals1, 10, 0.05, "normals1", v1);
  viewer->addPointCloudNormals<pcl::PointXYZRGB, pcl::Normal> (cloud, normals2, 10, 0.05, "normals2", v2);

  return (viewer);
}


unsigned int text_id = 0;
void keyboardEventOccurred (const pcl::visualization::KeyboardEvent &event,
                            void* viewer_void)
{
  pcl::visualization::PCLVisualizer *viewer = static_cast<pcl::visualization::PCLVisualizer *> (viewer_void);
  if (event.getKeySym () == "r" && event.keyDown ())
  {
    std::cout << "r was pressed => removing all text" << std::endl;

    char str[512];
    for (unsigned int i = 0; i < text_id; ++i)
    {
      sprintf (str, "text#%03d", i);
      viewer->removeShape (str);
    }
    text_id = 0;
  }
}

void mouseEventOccurred (const pcl::visualization::MouseEvent &event,
                         void* viewer_void)
{
  pcl::visualization::PCLVisualizer *viewer = static_cast<pcl::visualization::PCLVisualizer *> (viewer_void);
  if (event.getButton () == pcl::visualization::MouseEvent::LeftButton &&
      event.getType () == pcl::visualization::MouseEvent::MouseButtonRelease)
  {
    std::cout << "Left mouse button released at position (" << event.getX () << ", " << event.getY () << ")" << std::endl;

    char str[512];
    sprintf (str, "text#%03d", text_id ++);
    viewer->addText ("clicked here", event.getX (), event.getY (), str);
  }
}

pcl::visualization::PCLVisualizer::Ptr interactionCustomizationVis ()
{
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addCoordinateSystem (1.0);

  viewer->registerKeyboardCallback (keyboardEventOccurred, (void*)viewer.get ());
  viewer->registerMouseCallback (mouseEventOccurred, (void*)viewer.get ());

  return (viewer);
}


// --------------
// -----Main-----
// --------------
int
main (int argc, char** argv)
{
  // --------------------------------------
  // -----Parse Command Line Arguments-----
  // --------------------------------------
  if (pcl::console::find_argument (argc, argv, "-h") >= 0)
  {
    printUsage (argv[0]);
    return 0;
  }
    pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("test_pcd.pcd", *basic_cloud_ptr) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }

  bool simple(false), rgb(false), custom_c(false), normals( false),
    shapes(false), viewports(false), interaction_customization(false);
  if (pcl::console::find_argument (argc, argv, "-s") >= 0)
  {
    simple = true;
    std::cout << "Simple visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-c") >= 0)
  {
    custom_c = true;
    std::cout << "Custom colour visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-r") >= 0)
  {
    rgb = true;
    std::cout << "RGB colour visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-n") >= 0)
  {
    normals = true;
    std::cout << "Normals visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-a") >= 0)
  {
    shapes = true;
    std::cout << "Shapes visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-v") >= 0)
  {
    viewports = true;
    std::cout << "Viewports example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-i") >= 0)
  {
    interaction_customization = true;
    std::cout << "Interaction Customization example\n";
  }
  else
  {
    printUsage (argv[0]);
    return 0;
  }

  // ------------------------------------
  // -----Create example point cloud-----
  // ------------------------------------
  // pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
  std::cout << "Generating example point clouds.\n\n";
  // We're going to make an ellipse extruded along the z-axis. The colour for
  // the XYZRGB cloud will gradually go from red to green to blue.
  std::uint8_t r(255), g(0), b(0);
  std::cout << "size " << basic_cloud_ptr->points.size() << endl;
  for (int i=0; i < basic_cloud_ptr->points.size(); i++ )
  {
    
    pcl::PointXYZRGB point;
    point.x = basic_cloud_ptr->points[i].x;
    point.y = basic_cloud_ptr->points[i].y;
    point.z = basic_cloud_ptr->points[i].z;
    std::uint32_t rgb = (static_cast<std::uint32_t>(r) << 16 |
            static_cast<std::uint32_t>(g) << 8 | static_cast<std::uint32_t>(b));
    point.rgb = *reinterpret_cast<float*>(&rgb);
    point_cloud_ptr->points.push_back (point);
    if((i%1927)==0){
      r-=1;
      g+=1;
      b+=1;
    }    
    // if (basic_cloud_ptr->points[i].z < )
    // {
    //   r -= 12;
    //   g += 12;
    // }
    // else
    // {
    //   g -= 12;
    //   b += 12;
    // }
  }
  
  basic_cloud_ptr->width = basic_cloud_ptr->size ();
  basic_cloud_ptr->height = 1;
  point_cloud_ptr->width = point_cloud_ptr->size ();
  point_cloud_ptr->height = 1;

  // ----------------------------------------------------------------
  // -----Calculate surface normals with a search radius of 0.05-----
  // ----------------------------------------------------------------
  pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
  ne.setInputCloud (point_cloud_ptr);
  pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB> ());
  ne.setSearchMethod (tree);
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals1 (new pcl::PointCloud<pcl::Normal>);
  ne.setRadiusSearch (0.05);
  ne.compute (*cloud_normals1);

  // ---------------------------------------------------------------
  // -----Calculate surface normals with a search radius of 0.1-----
  // ---------------------------------------------------------------
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2 (new pcl::PointCloud<pcl::Normal>);
  ne.setRadiusSearch (0.1);
  ne.compute (*cloud_normals2);

  pcl::visualization::PCLVisualizer::Ptr viewer;
  if (simple)
  {
    viewer = simpleVis(basic_cloud_ptr);
  }
  else if (rgb)
  {
    viewer = rgbVis(point_cloud_ptr);
  }
  else if (custom_c)
  {
    viewer = customColourVis(basic_cloud_ptr);
  }
  else if (normals)
  {
    viewer = normalsVis(point_cloud_ptr, cloud_normals2);
  }
  else if (shapes)
  {
    viewer = shapesVis(point_cloud_ptr);
  }
  else if (viewports)
  {
    viewer = viewportsVis(point_cloud_ptr, cloud_normals1, cloud_normals2);
  }
  else if (interaction_customization)
  {
    viewer = interactionCustomizationVis();
  }

  //--------------------
  // -----Main loop-----
  //--------------------
  viewer->spin();
  // while (!viewer->wasStopped ())
  // {
  //   viewer->spinOnce (100);
  //   std::this_thread::sleep_for(100ms);
  // }
  
}