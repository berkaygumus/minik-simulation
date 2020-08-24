#include "RosThread.h"

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;
using namespace cv;


RosThread::RosThread(int argc,char** argv,int ID){

    this->argc = argc;
    this->argv = argv;

    this->id = ID;//robot ID

    //PARAMETERS FROM YAML FILE
    //goal topology
    vector<int>  topology_vector;
    getParamHandle.getParam("/goal_topology", topology_vector);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        this->A[i][j] = topology_vector[i*N+j];
      }
    }

    //ro_ij : ro_i + ro_j
    getParamHandle.getParam("/ro_ij", this->ro_ij);

    //k
    getParamHandle.getParam("/k", this->k);

    //threshold distance
    getParamHandle.getParam("/threshold", this->threshold);

    getParamHandle.getParam("/quite_mode", this->quite_mode);

    //eta initialization
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(A[i][j]==1){
          eta[i][j] = threshold - ro_ij;
        }
        else if(A[i][j]==0){
          eta[i][j] = threshold + ro_ij;
        }
      }
    }
}

RosThread::~RosThread(){

}

double RosThread::orientation2theta(double x, double y, double z, double w){
  //calculates angles using quaternion
  double siny_cosp = 2*(w*z + x*y);
  double cosy_cosp = 1 - 2*(y*y + z*z);
  double theta = atan2(siny_cosp,cosy_cosp);
  return theta;
}



////////////////////////////////TURTLESIM SIMULATOR POS CALLBACK//////////////////////////

/*void RosThread::poseOdomCallback0(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 0;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback1(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 1;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback2(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 2;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback3(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 3;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback4(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 4;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback5(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 5;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}

void RosThread::poseOdomCallback6(const turtlesim::Pose::ConstPtr& msg){
  //ROS_INFO("00: [%d] , 01: [%d]  " , A[0][0], A[0][1]);
  int temp_id = 6;
  b[temp_id][0] = msg->x;
  b[temp_id][1] = msg->y;
  if(id==temp_id){
    pose_x = msg->x;
    pose_y = msg->y;
    pose_theta = msg->theta;
  }


  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->x;
    calcPos[j][temp_id][1] = msg->y;

  }

  flagN[temp_id]=1;
}*/


//////////////////////////////////////////////////////////////////////////


//////////////////////////////////COMPLETED PART //////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////GAZEBO POS CALLBACK ///////////////////////
/*
void RosThread::gazeboOdomCallback0(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 0;
  cout << "robot 1" << endl;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);///??????????
  }
  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y;

  }

  flagN[temp_id] = 1;
}

void RosThread::gazeboOdomCallback1(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 1;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);///??????????
  }
  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y;

  }
  flagN[temp_id] = 1;
}

void RosThread::gazeboOdomCallback2(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 2;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);///??????????
  }
  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y;

  }
  flagN[temp_id] = 1;
}

void RosThread::gazeboOdomCallback3(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 3;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);///??????????
  }
  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y;

  }
  flagN[temp_id] = 1;
}

void RosThread::gazeboOdomCallback4(const nav_msgs::Odometry::ConstPtr& msg){
  int temp_id = 4;
  if(temp_id == id){
    pose_theta = orientation2theta(0, 0, msg->pose.pose.orientation.z, msg->pose.pose.orientation.w);///??????????
  }
  for(int j=0;j<n;j++){
    calcPos[j][temp_id][0] = msg->pose.pose.position.x;
    calcPos[j][temp_id][1] = msg->pose.pose.position.y;

  }
  flagN[temp_id] = 1;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////PARTIAL PART///////////////////////////////////////////////////////////////////////////////

//subscribers for odometry from gazebo

void RosThread::odomCallback0(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==0){
    pose_theta = msg->position.z;//heading
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));//path distance update
      prev_pose_x = pose_x;//previous position
      prev_pose_y = pose_y;
    }

    cout << "path distance robot1: " << path_distance << endl;
  }
}

void RosThread::odomCallback1(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback1: " << t << endl;
  if(id ==1){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot2: " << path_distance << endl;

    }
  }


void RosThread::odomCallback2(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==2){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot3: " << path_distance << endl;
  }
}

void RosThread::odomCallback3(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==3){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot4: " << path_distance << endl;
  }
}

void RosThread::odomCallback4(const geometry_msgs::Pose::ConstPtr& msg){
  //cout << "callback0: " << t << endl;
  if(id ==4){
    pose_theta = msg->position.z;
    if(!completed_stop){
      pose_x = msg->position.x;
      pose_y = msg->position.y;
      path_distance = path_distance + sqrt(pow(prev_pose_x-pose_x,2)+pow(prev_pose_y-pose_y,2));
      prev_pose_x = pose_x;
      prev_pose_y = pose_y;
    }
    cout << "path distance robot5: " << path_distance << endl;
  }
}

//subscribers for robot positions calculated at pos_calculator package
void RosThread::calcPosCallback0(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 0;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;//calcPos[reference frame][target]
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcPosCallback1(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 1;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcPosCallback2(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 2;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcPosCallback3(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 3;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

void RosThread::calcPosCallback4(const geometry_msgs::PoseArray::ConstPtr& msg){
  int temp_id = 4;
  for(int j=0;j<n;j++){
    calcPos[temp_id][j][0] = msg->poses[j].position.x;
    calcPos[temp_id][j][1] = msg->poses[j].position.y;

  }
}

//subscriber for signal whether transformation is completed
void RosThread::transformCallback(const std_msgs::Bool::ConstPtr& msg){
  isSeen = msg->data;
  if(!quite_mode){
    cout << "isSeen: " << isSeen << endl;
  }
}

//////////////////////////////////////////////////////////////////////////////////////

void RosThread::distanceCalculator(){
  //calculates distances among robots
  for(int i=0;i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        distance[i][j]=sqrt(pow(calcPos[i][i][0]-calcPos[i][j][0],2)+pow(calcPos[i][i][1]-calcPos[i][j][1],2));
        distance[j][i] = distance[i][j];
        if(!quite_mode){
          if(i<j){
            cout << "distance " << i << j << " " << distance[i][j] << endl;
          }
        }
      }
    }
  }
}

/*void turtleService(const turtlesim::Spawn::ConstPtr& ser){


}*/

/*void RosThread::poseOverCallback(const ISLH_msgs::robotPositions::ConstPtr& msg){
  for(int i =0;i<N ; i++){
		b[i][0] = msg->positions[i].x;
		b[i][1] = msg->positions[i].y;
		//b[i][2] = msg->directions[i];
	}

}*/


void RosThread::gamaFinder(){
  //calculates gamma values
  gama_sum = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i<j){
        gama_sum = gama_sum + A[i][j]*pow( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ,2) + (1-A[i][j])*pow( pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2) ,2);

      }
    }
  }
  if(!quite_mode){
    cout << "gama_sum: " << gama_sum << endl;
  }
}

void RosThread::gamaBDotFinder(){
  //calculates derivative of gamma with respect to b(position) >> gama_b_dot
  for(int i=0; i<N;i++){//i >> robot id
    gama_b_dot[i][0] = 0;
    gama_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(j!=i){
        gama_b_dot[i][0] = gama_b_dot[i][0] + 4*(calcPos[i][i][0]-calcPos[i][j][0])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
        gama_b_dot[i][1] = gama_b_dot[i][1] + 4*(calcPos[i][i][1]-calcPos[i][j][1])*(A[i][j]*( pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2) ) + (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
      }
    }

    if(!quite_mode){
      cout << "gama_b_dot " << i <<  " 0: " << gama_b_dot[i][0] << endl;
      cout << "gama_b_dot " << i <<  " 1: " << gama_b_dot[i][1] << endl;
    }
  }
}

void RosThread::betaFinder(){
  //calculates beta values
  beta_product = 1;
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i<j){
        beta_product = beta_product*(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }
  }
  if(!quite_mode){
    cout << "beta_product: " << beta_product << endl;
  }
}

void RosThread::betaBDotFinder(){
  //calculates derivative of beta with respect to b(position) >> beta_b_dot
  for(int i = 0; i<N; i++){
    beta_b_dot[i][0] = 0;
    beta_b_dot[i][1] = 0;
    for(int j=0; j<N; j++){
      if(i!=j){
        beta_b_dot[i][0] = beta_b_dot[i][0] + 2*(calcPos[i][i][0]-calcPos[i][j][0])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
        beta_b_dot[i][1] = beta_b_dot[i][1] + 2*(calcPos[i][i][1]-calcPos[i][j][1])*beta_product/(pow(distance[i][j],2)-pow(ro_ij,2));
      }
    }
    if(!quite_mode){
      cout << "beta_b_dot " << i <<  " 0 " << beta_b_dot[i][0] << endl;
      cout << "beta_b_dot " << i <<  " 1 " << beta_b_dot[i][1] << endl;
    }
  }
}

void RosThread::gamaEtaDotFinder(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      gama_eta_dot[i][j] = 0;
      if(i!=j){
        gama_eta_dot[i][j] = 4*eta[i][j]*( A[i][j]*(pow(distance[i][j],2) - pow(threshold,2) + pow(eta[i][j],2)) - (1-A[i][j])*(pow(distance[i][j],2) - pow(threshold,2) - pow(eta[i][j],2)) );
        //cout << "gama_eta_dot " << i << j << " " << gama_eta_dot[i][j] << endl;
      }
    }
  }
}

void RosThread::fiBDotFinder(){
  //calculates derivative of fi with respect to b(position) >> fi_b_dot
  for(int i=0; i<N; i++){
    for(int j=0; j<2;j++){
      fi_b_dot[i][j] = -(1/k)*pow(pow(gama_sum,k)/(beta_product+pow(gama_sum,k)),((1/k)-1))*(k*pow(gama_sum,k-1)*gama_b_dot[i][j]*(beta_product+pow(gama_sum,k))-pow(gama_sum,k)*(beta_b_dot[i][j]+k*pow(gama_sum,k-1)*gama_b_dot[i][j]))/pow((beta_product+pow(gama_sum,k)),2);
      if(!quite_mode){
        cout << "fi_b_dot " << i << " " << j << " " << fi_b_dot[i][j] << endl;
      }
    }
  }
}

void RosThread::fiEtaDotFinder(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        fi_eta_dot[i][j] = -pow((pow(gama_sum,k)/(beta_product+pow(gama_sum,k))),(1/k)-1)*beta_product*pow(gama_sum,(k-1))*gama_eta_dot[i][j]/pow((beta_product+pow(gama_sum,k)),2);

        if(fi_eta_dot[i][j]>-999999999){
            //cout << "fi_eta_dot " << i << j << " "<< fi_eta_dot[i][j] << endl;
        }
      }
    }
  }
}


void RosThread::etaFinder(){
  //calculates eta values using runge kutta

  //cout << "differential: " << endl;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i!=j){
        fi_eta_dot2[i][j] = -pow((pow(gama_sum,k)/(beta_product+pow(gama_sum,k))),(1/k)-1)*beta_product*pow(gama_sum,(k-1))*gama_eta_dot[i][j]/pow((beta_product+pow(gama_sum,k)),2);
        //cout << "diff fi_eta_dot " << i << j << " " << step_size * fi_eta_dot2[i][j] << endl;
        //cout << "diff eta_dot " << i << j << " " << eta[i][j] + step_size * fi_eta_dot2[i][j] << endl;
      }
    }
  }


  //cout << "runge kutta " << endl;
  double temp_eta[N][N];
  double k1[N][N],k2[N][N],k3[N][N],k4[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      temp_eta[i][j] = eta[i][j];

    }
  }

  RosThread::fiEtaDotFinder();//eta0

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot0 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k1[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k1  " << i << j << " " << k1[i][j] << endl;
      eta[i][j] = eta[i][j] + k1[i][j] /2;


    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k1/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot1 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k2[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k2  " << i << j << " " << k2[i][j] << endl;
      eta[i][j] = eta[i][j] + k2[i][j] /2 - k1[i][j] /2;


    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k2/2

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot2 " << i << j << " " << fi_eta_dot[i][j] << " step size " << step_size << endl;
      k3[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k3  " << i << j << " " << k3[i][j] << endl;
      eta[i][j] = eta[i][j] + k3[i][j] - k2[i][j] /2;;

    }
  }

  RosThread::fiEtaDotFinder();//eta0 + k3

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      //cout << "fi_eta_dot3 " << i << j << " " << fi_eta_dot[i][j] << endl;
      k4[i][j] = step_size * fi_eta_dot[i][j];
      //cout << "k4  " << i << j << " " << k4[i][j] << endl;

    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        eta[i][j] = temp_eta[i][j] + k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6;
        if(i!=j){
          /*cout << "runge delta eta :" << i << j << " " << k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6 <<endl;
          cout << "differential eta: " << fi_eta_dot2[i][j]*step_size << endl;
          cout << "runga eta " << i << j << " " << eta[i][j] <<endl;
          cout << "diff runge and diff " <<  step_size * fi_eta_dot2[i][j] - (  k1[i][j]/6 + k2[i][j]/3 + k3[i][j]/3 + k4[i][j]/6  ) << endl;*/
          if(!quite_mode){
            cout << "fi eta dot " << i << j << " " << fi_eta_dot[i][j] <<endl;
          }
        }

    }
  }



  /*for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i!=j){
        if(fi_eta_dot[i][j]>-999999999){
            eta[i][j] = eta[i][j] + fi_eta_dot[i][j]/f ;////derivative
            cout << "eta " << i << j << " " << eta[i][j] <<endl;
        }
      }

    }
  }*/
}

void RosThread::Comparator(){
  //checks goal topology is realized
  completed = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i<j){
          if(distance[i][j] < threshold){
            completed = completed * A[i][j];
          }
          else{
            completed = completed * (1-A[i][j]);
          }
      }
    }
  }
  if(completed == 1){
    cout << "MISSION COMPLETED !!! " << endl;
  }
  else{
    cout << "next time :(" << endl;
  }
}

void RosThread::finalRealization(){
  //calculates velocities and eta values
  RosThread::gamaFinder(); //calculates gamma
  RosThread::gamaBDotFinder(); //calculates derivative of gamma with respect to b(position)
  RosThread::betaFinder(); //calculates beta
  RosThread::betaBDotFinder(); //calculates derivative of beta with respect to b(position)
  RosThread::gamaEtaDotFinder(); //calculates derivative of gamma with respect to eta
  RosThread::fiBDotFinder(); //calculates derivative of fi with respect to b(position)
  //RosThread::fiEtaDotFinder();
  RosThread::etaFinder(); //calculates new eta values using runge kutta
  RosThread::setVelocity();//calculates linear and angular velocities
  RosThread::Comparator(); //checks goal topology is realized

}

void RosThread::setVelocity(){
  double vx, vy;
  cout << "completed: " << completed << endl;
  if(completed == 1){//if goal topology is realized
    time_counter ++;
    if(time_counter>100){ //if it lasts 10 seconds
      vx = 0;
      vy = 0;
      cout <<"set velocity zero" << endl;
      completed_stop = 1;
    }
    else{//waits 10 seconds to stop
      cout << "completed but continue" << endl;
      vx = fi_b_dot[id][0];
      vy = fi_b_dot[id][1];
      completed_stop = 0;
    }

  }
  else{//if goal topology is not realized
    time_counter = 0;
    vx = fi_b_dot[id][0];
    vy = fi_b_dot[id][1];
    completed_stop = 0;
  }

  double v = sqrt(pow(vx,2)+pow(vy,2));


  double velocity_angle;
  bool velZero = false;
  if(vx==0){
    if(vy==0){
      velZero = true;
      linear_vel = 0;
      angular_vel = 0;
    }
    else if(vy>0){
      velocity_angle = PI/2;
    }
    else if(vy<0){
      velocity_angle = -PI/2;
    }

  }
  else{
    velocity_angle = atan(vy/vx);//velocity angle
    if(vx<0){
      velocity_angle = velocity_angle + PI;
    }
  }

  if(velZero==false){
    double delta_angle = velocity_angle-pose_theta;//angle between heading and velocity calculated by realization
    linear_vel = cos(delta_angle)*0.2; //linear velocity; max linear velocity is 0.2
    angular_vel = sin(delta_angle)*PI/3; //angular velocity; max angular velocity is PI/3
  }
}



void RosThread::turnToSee(){
  //turns to observe other robots
  geometry_msgs::Twist msg;

  msg.linear.x = 0; //zero linear velocity
  msg.angular.z = PI/4; //angular velocity

  vel_pub.publish(msg);

}


void RosThread::work(){

  ostringstream ss;
  ss << id + 1;
  string name =  "robot" + ss.str(); //message name for velocity at gazebo

  vel_pub = velPub.advertise<geometry_msgs::Twist>(name+"/cmd_vel", 100);//publisher for velocity at gazebo

  //ros::Publisher vel_pub = velPub.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
  /*ros::Subscriber pose_odom_sub1 = poseOdomSub.subscribe("turtle1/pose",1000,&RosThread::poseOdomCallback0,this);
  ros::Subscriber pose_odom_sub2 = poseOdomSub.subscribe("turtle2/pose",1000,&RosThread::poseOdomCallback1,this);
  ros::Subscriber pose_odom_sub3 = poseOdomSub.subscribe("turtle3/pose",1000,&RosThread::poseOdomCallback2,this);
  ros::Subscriber pose_odom_sub4 = poseOdomSub.subscribe("turtle4/pose",1000,&RosThread::poseOdomCallback3,this);
  ros::Subscriber pose_odom_sub5 = poseOdomSub.subscribe("turtle5/pose",1000,&RosThread::poseOdomCallback4,this);
  ros::Subscriber pose_odom_sub6 = poseOdomSub.subscribe("turtle6/pose",1000,&RosThread::poseOdomCallback5,this);
  ros::Subscriber pose_odom_sub7 = poseOdomSub.subscribe("turtle7/pose",1000,&RosThread::poseOdomCallback6,this);
*/

  ////////////////////////partial part///////////////////////////////////////////////////////////////////////////////////
  //subscribers for odometry from gazebo
  ros::Subscriber odom_sub1 = poseSub.subscribe("/odom1",1000,&RosThread::odomCallback0,this);
  ros::Subscriber odom_sub2 = poseSub.subscribe("/odom2",1000,&RosThread::odomCallback1,this);
  ros::Subscriber odom_sub3 = poseSub.subscribe("/odom3",1000,&RosThread::odomCallback2,this);
  ros::Subscriber odom_sub4 = poseSub.subscribe("/odom4",1000,&RosThread::odomCallback3,this);
  ros::Subscriber odom_sub5 = poseSub.subscribe("/odom5",1000,&RosThread::odomCallback4,this);

  //subscriber for completed signal
  ros::Subscriber tr_sub = trSub.subscribe("/transformCompleted",1000,&RosThread::transformCallback,this);

  //subscribers for calculated positions
  ros::Subscriber calc_sub1 = poseSub.subscribe("/completedPos0",1000,&RosThread::calcPosCallback0,this);
  ros::Subscriber calc_sub2 = poseSub.subscribe("/completedPos1",1000,&RosThread::calcPosCallback1,this);
  ros::Subscriber calc_sub3 = poseSub.subscribe("/completedPos2",1000,&RosThread::calcPosCallback2,this);
  ros::Subscriber calc_sub4 = poseSub.subscribe("/completedPos3",1000,&RosThread::calcPosCallback3,this);
  ros::Subscriber calc_sub5 = poseSub.subscribe("/completedPos4",1000,&RosThread::calcPosCallback4,this);
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 /////////////////////completed part ////////////////////////////////////////////////////////////////////////////////////
/*
  ros::Subscriber calc_sub11 = poseSub.subscribe("/robot1/odom",1000,&RosThread::gazeboOdomCallback0,this);
  ros::Subscriber calc_sub21 = poseSub.subscribe("/robot2/odom",1000,&RosThread::gazeboOdomCallback1,this);
  ros::Subscriber calc_sub31 = poseSub.subscribe("/robot3/odom",1000,&RosThread::gazeboOdomCallback2,this);
  ros::Subscriber calc_sub41 = poseSub.subscribe("/robot4/odom",1000,&RosThread::gazeboOdomCallback3,this);
  ros::Subscriber calc_sub51 = poseSub.subscribe("/robot5/odom",1000,&RosThread::gazeboOdomCallback4,this);
*/
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  //ros::Subscriber pose_over_sub=poseOverheadCamSub.subscribe<ISLH_msgs::robotPositions>("robots_final_positions",1,&RosThread::poseOverCallback,this);

  ros::Rate loop_rate(f);


  while (ros::ok()){

  /*  flag = 1;
    for(int i=0;i<N;i++){
      flag = flag * flagN[i];
    }
*/
    cout << "isSeen2: " << isSeen << endl;
    if(isSeen){//if transformations are completed and positions are calculated
      RosThread::distanceCalculator();//calculates distances among robots
      RosThread::finalRealization(); //realization algortihm

      geometry_msgs::Twist msg;//velocity message

      msg.linear.x = this->linear_vel;
      msg.angular.z = this->angular_vel;

      vel_pub.publish(msg); //publishes velocity message
    }

    else{
      //turnToSee();
      geometry_msgs::Twist msg;//velocity message to turn

      msg.linear.x = 0;
      msg.angular.z = 0.8;


      vel_pub.publish(msg); //publishes velocity message
      ROS_INFO("turning...");
    }

    ros::spinOnce();
    loop_rate.sleep();
  }
}
