#include <iostream>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

// This function displays the help
void showHelp(char *program_name)
{
    std::cout << std::endl;
    std::cout << "Usage: " << program_name << " cloud_filename.[pcd|ply]" << std::endl;
    std::cout << "-h: Show this help." << std::endl; 
}

// Main function
int main(int argc,char **argv)
{
    // Show help
    if(pcl::console::find_switch(argc,argv,"-h") || pcl::console::find_switch(argc,argv,"--help"))
    {
        showHelp(argv[0]);
        return 0; 
    }

    // Fetch point cloud filename in arguments | Works with PLY files
    std::vector<int> filenames;

    filenames = pcl::console::parse_file_extension_argument(argc,argv,".ply");



    // Visualization 
    printf("\n Point cloud colors :\n"
        " \t white \t = \t original point cloud \n");

    pcl::visualization::PCLVisualizer viewer(" Point Cloud Visualizer");
    viewer.setBackgroundColor(0.05,0.05,0.05,0); // Set background to a dark grey

    // Load file | Works with PLY files
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZRGB> ());

    for(int i=0; i<argc-1; i++)
    {

    cout<<argv[filenames[i]]<<endl;

            if(pcl::io::loadPLYFile(argv[filenames[i]],*source_cloud) < 0)
            {
                std::cout << "Error loading point cloud " << argv[filenames[i+1]] << std::endl << std::endl;
                showHelp (argv[i+1]);
                return -1;
            }


        // Define R,G,B colors for the point cloud 
        pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(source_cloud);
    //  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_cloud_color_handler(source_cloud,255,255,255); // White

        // We add the point cloud to the viewer and pass the color handler 
    if(i!=0){
        viewer.removePointCloud("original_cloud"+(i-1));
    }
        viewer.addPointCloud(source_cloud,rgb,"original_cloud"+i);
        viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,2,"original_cloud"+i);

    // viewer.spinOnce(100, true);
        }
        while(!viewer.wasStopped()){
           viewer.spinOnce();
        }

            return 0;
} // End main()