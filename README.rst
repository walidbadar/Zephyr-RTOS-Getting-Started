.. _getting_started:

Getting Started Guide
#####################

Follow this guide to:

- Set up a command-line Zephyr development environment on Ubuntu, macOS, or
  Windows
- Get the source code
- Build, flash, and run a sample application

.. _host_setup:

Install dependencies
********************

Next, you'll install some host dependencies using your package manager.

The current minimum required version for the main dependencies are:

.. list-table::
   :header-rows: 1

* - Tool
* - [CMake](https://cmake.org/)

* - [Python](https://www.python.org/)

* - [Devicetree compiler](https://www.devicetree.org/)

Get Zephyr and install Python dependencies
******************************************

Next, clone Zephyr and its :ref:modules <modules> into a new :ref:west
<west> workspace named :file:zephyrproject. You'll also install Zephyr's
additional Python dependencies.

Windows

#. Open a cmd.exe terminal window **as a regular user**

#. Install west:

   .. code-block:: bat

      pip3 install -U west

#. Get the Zephyr source code:

   .. code-block:: bat

      cd %HOMEPATH%
      west init zephyrproject
      cd zephyrproject
      west update

#. Export a :ref:Zephyr CMake package <cmake_pkg>. This allows CMake to
   automatically load boilerplate code required for building Zephyr
   applications.

   .. code-block:: bat

      west zephyr-export

#. Zephyr's `scripts\requirements.txt file declares additional Python
   dependencies. Install them with `pip3.

   .. code-block:: bat

      pip3 install -r %HOMEPATH%\zephyrproject\zephyr\scripts\requirements.txt


Install the Zephyr SDK
**********************

The :ref:Zephyr Software Development Kit (SDK) <toolchain_zephyr_sdk>
contains toolchains for each of Zephyr's supported architectures, which
include a compiler, assembler, linker and other programs required to build
Zephyr applications.

It also contains additional host tools, such as custom QEMU and OpenOCD builds
that are used to emulate, flash and debug Zephyr applications.

.. include:: ../toolchains/zephyr_sdk.rst
   :start-after: toolchain_zephyr_sdk_install_start
   :end-before: toolchain_zephyr_sdk_install_end

.. _getting_started_run_sample:

Build the Blinky Sample
***********************

.. note::

   :zephyr:code-sample:blinky is compatible with most, but not all, :ref:boards. If your board
   does not meet Blinky's :ref:blinky-sample-requirements, then
   :ref:hello_world is a good alternative.

   If you are unsure what name west uses for your board, `west boards
   can be used to obtain a list of all boards Zephyr supports.

Build the :zephyr:code-sample:blinky with :ref:west build <west-building>, changing
`<your-board-name> appropriately for your board:

.. tabs::

   .. group-tab:: Ubuntu

      .. code-block:: bash

         cd ~/zephyrproject/zephyr
         west build -p always -b <your-board-name> samples/basic/blinky

   .. group-tab:: macOS

      .. code-block:: bash

         cd ~/zephyrproject/zephyr
         west build -p always -b <your-board-name> samples/basic/blinky

   .. group-tab:: Windows

      .. code-block:: bat

         cd %HOMEPATH%\zephyrproject\zephyr
         west build -p always -b <your-board-name> samples\basic\blinky

The `-p always option forces a pristine build, and is recommended for new
users. Users may also use the `-p auto option, which will use
heuristics to determine if a pristine build is required, such as when building
another sample.

.. note::

   A board may contain one or multiple SoCs, Also, each SoC may contain one or
   more CPU clusters.
   When building for such boards it is necessary to specify the SoC or CPU
   cluster for which the sample must be built.
   For example to build :zephyr:code-sample:blinky for the `cpuapp core on
   the :ref:nRF5340DK <nrf5340dk_nrf5340> the board must be provided as:
   `nrf5340dk/nrf5340/cpuapp. See also :ref:board_terminology for more
   details.

Flash the Sample
****************

Connect your board, usually via USB, and turn it on if there's a power switch.
If in doubt about what to do, check your board's page in :ref:boards.

Then flash the sample using :ref:west flash <west-flashing>:

.. code-block:: shell

   west flash

Useful links to Learn The Zephyr Project.
=========================================
* 🔗 Tutorial: Mastering Zephyr Driver Development: https://lnkd.in/d_4wUpdk
* 🔗 ESP32 on Zephyr OS: https://lnkd.in/deqTWkdy
* 🔗 nRF Connect SDK Fundamentals course: https://lnkd.in/ds_urNDj
* 🔗 Memfault Article: https://lnkd.in/d4VFwHsM
