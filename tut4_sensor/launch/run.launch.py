from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='tut4_sensor', executable='sensor_pub', output='screen'),
        Node(package='tut4_sensor', executable='sensor_sub', output='screen'),
    ])
