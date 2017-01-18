import cx_Freeze

executables = [cx_Freeze.Executable("shooter_client.py"),cx_Freeze.Executable("shooter_server.py")]

cx_Freeze.setup(
    name="BoxGame",
    options={"build_exe": {"packages":["pygame", "PodSixNet", "math", "time", "random"],
                           "include_files":["data"]}},
    executables = executables

    )
