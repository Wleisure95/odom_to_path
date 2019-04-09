# odom_to_path
使用ros时，将/odom话题里的里程计数据转成path方便在rviz上路径可视化.

1.  在工作空间的src文件夹下执行 git clone git@github.com:Wleisure95/odom_to_path.git
2.  退回工作空间 catkin_make
3.  roslaunch odom_to_path odom_to_path.launch.执行启动,可在该launch文件里remap话题名字。

