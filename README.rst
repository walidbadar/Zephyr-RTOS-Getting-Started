<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Getting Started Guide</title>
    <style>
        body {
            font-family: Arial, sans-serif;
        }
        h1, h2, h3, h4, h5, h6 {
            color: #333;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border: 1px solid #ddd;
            overflow-x: auto;
        }
        code {
            background-color: #f9f2f4;
            padding: 2px 4px;
            font-size: 90%;
            color: #c7254e;
            border-radius: 4px;
        }
        .tabs {
            margin-top: 20px;
        }
        .group-tab, .group-tab-content {
            display: none;
        }
        .group-tab:target + .group-tab-content {
            display: block;
        }
        .note {
            background-color: #eef;
            border-left: 4px solid #88f;
            padding: 10px;
            margin-bottom: 10px;
        }
        .list-table {
            width: 100%;
            border-collapse: collapse;
            margin-bottom: 20px;
        }
        .list-table th, .list-table td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: left;
        }
        .list-table th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>

<h1>Getting Started Guide</h1>

<p>Follow this guide to:</p>
<ul>
    <li>Set up a command-line Zephyr development environment on Ubuntu, macOS, or Windows</li>
    <li>Get the source code</li>
    <li>Build, flash, and run a sample application</li>
</ul>

<h2 id="host_setup">Install dependencies</h2>

<p>Next, you'll install some host dependencies using your package manager.</p>

<p>The current minimum required version for the main dependencies are:</p>

<table class="list-table">
    <thead>
        <tr>
            <th>Tool</th>
            <th>Min. Version</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td><a href="https://cmake.org/">CMake</a></td>
            <td>3.20.5</td>
        </tr>
        <tr>
            <td><a href="https://www.python.org/">Python</a></td>
            <td>3.10</td>
        </tr>
        <tr>
            <td><a href="https://www.devicetree.org/">Devicetree compiler</a></td>
            <td>1.4.6</td>
        </tr>
    </tbody>
</table>

<div class="tabs">
    <h3>Ubuntu</h3>

    <h4 id="install_dependencies_ubuntu">Install dependencies on Ubuntu</h4>

    <ol>
        <li>If using an Ubuntu version older than 22.04, it is necessary to add extra repositories to meet the minimum required versions for the main dependencies listed above. In that case, download, inspect and execute the Kitware archive script to add the Kitware APT repository to your sources list. A detailed explanation of <code>kitware-archive.sh</code> can be found here <a href="https://apt.kitware.com/">kitware third-party apt repository</a>:</li>

        <pre><code>wget https://apt.kitware.com/kitware-archive.sh
sudo bash kitware-archive.sh</code></pre>

        <li>Use <code>apt</code> to install the required dependencies:</li>

        <pre><code>sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget \
  python3-dev python3-pip python3-setuptools python3-tk python3-wheel xz-utils file \
  make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1</code></pre>

        <li>Verify the versions of the main dependencies installed on your system by entering:</li>

        <pre><code>cmake --version
python3 --version
dtc --version</code></pre>

        <p>Check those against the versions in the table in the beginning of this section. Refer to the <a href="#installation_linux">installation_linux</a> page for additional information on updating the dependencies manually.</p>
    </ol>

    <h3>macOS</h3>

    <h4 id="install_dependencies_macos">Install dependencies on macOS</h4>

    <ol>
        <li>Install <a href="https://brew.sh/">Homebrew</a>:</li>

        <pre><code>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</code></pre>

        <li>After the Homebrew installation script completes, follow the on-screen instructions to add the Homebrew installation to the path.</li>

        <ul>
            <li>On macOS running on Apple Silicon, this is achieved with:</li>

            <pre><code>(echo; echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> ~/.zprofile
source ~/.zprofile</code></pre>

            <li>On macOS running on Intel, use the command for Apple Silicon, but replace <code>/opt/homebrew/</code> with <code>/usr/local/</code>.</li>
        </ul>

        <li>Use <code>brew</code> to install the required dependencies:</li>

        <pre><code>brew install cmake ninja gperf python3 ccache qemu dtc libmagic wget openocd</code></pre>

        <li>Add the Homebrew Python folder to the path, in order to be able to execute <code>python</code> and <code>pip</code> as well <code>python3</code> and <code>pip3</code>.</li>

        <pre><code>(echo; echo 'export PATH="'$(brew --prefix)'/opt/python/libexec/bin:$PATH"') >> ~/.zprofile
source ~/.zprofile</code></pre>
    </ol>

    <h3>Windows</h3>

    <p class="note">
        Due to issues finding executables, the Zephyr Project doesn't currently support application flashing using the <a href="https://msdn.microsoft.com/en-us/commandline/wsl/install_guide">Windows Subsystem for Linux (WSL)</a> (WSL).
        Therefore, we don't recommend using WSL when getting started.
    </p>

    <p>These instructions must be run in a <code>cmd.exe</code> command prompt terminal window. In modern version of Windows (10 and later) it is recommended to install the Windows Terminal application from the Microsoft Store. The required commands differ on PowerShell.</p>

    <p>These instructions rely on <a href="https://chocolatey.org/">Chocolatey</a>. If Chocolatey isn't an option, you can install dependencies from their respective websites and ensure the command line tools are on your <code>PATH</code> <a href="#env_vars">environment variable</a>.</p>
