from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='tut2_counter', executable='counter_pub', output='screen'),
        Node(package='tut2_counter', executable='counter_sub', output='screen'),
    ])
