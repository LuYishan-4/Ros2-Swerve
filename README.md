# Swerve

```bash
docker build -t ros-swerve-env .
```

```bash
docker run --rm -it --name swerve-container -v "$(pwd):/swerve" ros-swerve-env
```

```bash
docker exec -it swerve-container bash
```

```bash
make
```

```bash
./swerve_robot
```

```bash
make clean
```
