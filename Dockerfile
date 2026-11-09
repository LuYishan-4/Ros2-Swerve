# =============================================================================
#  Ros Swerve 
# =============================================================================
ARG DEMO_BASE_IMAGE=ros:jazzy-ros-core
FROM ${DEMO_BASE_IMAGE}

RUN apt-get update \
    && apt-get install -y --no-install-recommends gcc libc6-dev make \
    && rm -rf /var/lib/apt/lists/*

COPY . /swerve

# The base's entrypoint sources ROS only for the first shell; `docker exec`
# bypasses it, so extra terminals get ROS from .bashrc.
RUN echo 'source /opt/ros/jazzy/setup.bash' >> /root/.bashrc

WORKDIR /swerve
CMD ["bash"]
