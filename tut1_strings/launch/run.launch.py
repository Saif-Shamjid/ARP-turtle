from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='tut1_strings', executable='talker', output='screen'),
        Node(package='tut1_strings', executable='listener', output='screen'),
    ])
