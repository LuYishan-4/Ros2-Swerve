# =============================================================================
#  Ros Swerve
# =============================================================================
ARG DEMO_BASE_IMAGE=ros:jazzy-ros-core
FROM ${DEMO_BASE_IMAGE}

RUN apt-get update && apt-get install -y \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

RUN ROS_INC="$(ls -d /opt/ros/${ROS_DISTRO}/include/* | paste -sd:)" \
    && printf '%s\n' \
    '#!/bin/sh' \
    "export CPATH=\"src/lib/controller:${ROS_INC}\${CPATH:+:\$CPATH}\"" \
    'for a in "$@"; do case "$a" in -c|-S|-E) exec /usr/bin/g++ "$@";; esac; done' \
    "exec /usr/bin/g++ \"\$@\" -L/opt/ros/${ROS_DISTRO}/lib -Wl,--disable-new-dtags,-rpath,/opt/ros/${ROS_DISTRO}/lib -lrclcpp -lrcutils" \
    > /usr/local/bin/g++ \
    && chmod +x /usr/local/bin/g++

COPY . /swerve

RUN echo 'source /opt/ros/jazzy/setup.bash' >> /root/.bashrc

WORKDIR /swerve
CMD ["bash"]
