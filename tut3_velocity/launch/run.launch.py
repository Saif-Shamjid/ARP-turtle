from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='tut3_velocity', executable='velocity_pub', output='screen'),
        Node(package='tut3_velocity', executable='velocity_sub', output='screen'),
    ])
