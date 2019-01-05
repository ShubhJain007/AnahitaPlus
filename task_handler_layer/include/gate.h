#ifndef GATE_H
#define GATE_H

#include <ros/ros.h>

#include <std_msgs/Float32.h>

#include <boost/thread.hpp>
#include <string>

#include <motion_layer/forwardPIDAction.h>
#include <motion_layer/upwardPIDAction.h>
#include <motion_layer/sidewardPIDAction.h>
#include <motion_layer/anglePIDAction.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include <task_handler.h>

class gateTask
{
private:
    ros::NodeHandle nh_;
    boost::thread* spin_thread;

    actionlib::SimpleActionClient<motion_layer::forwardPIDAction> forwardPIDClient;
    actionlib::SimpleActionClient<motion_layer::upwardPIDAction> upwardPIDClient;
    actionlib::SimpleActionClient<motion_layer::sidewardPIDAction> sidewardPIDClient;
    actionlib::SimpleActionClient<motion_layer::anglePIDAction> anglePIDClient;

    motion_layer::sidewardPIDGoal sidewardPIDgoal;
    motion_layer::forwardPIDGoal forwardPIDgoal;
    motion_layer::upwardPIDGoal upwardPIDgoal;
    motion_layer::anglePIDGoal anglePIDGoal;

    taskHandler th;

public:
    gateTask();
    ~gateTask();

    void setActive(bool);
};

#endif // GATE_H