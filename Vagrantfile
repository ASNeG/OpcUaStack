$script = <<-SCRIPT
function Invoke-BatchFile
{
    param([string]$Path, [string]$Parameters)

    $tempFile = [IO.Path]::GetTempFileName()

    ## Store the output of cmd.exe.  We also ask cmd.exe to output
    ## the environment table after the batch file completes
    cmd.exe /c " `"$Path`" $Parameters && set " > $tempFile

    ## Go through the environment variables in the temp file.
    ## For each of them, set the variable in our local environment.
    Get-Content $tempFile | Foreach-Object {
        if ($_ -match "^(.*?)=(.*)$") {
            Set-Content "env:\$($matches[1])" $matches[2]
        }
        else {
            $_
        }
    }

    Remove-Item $tempFile
}


Invoke-BatchFile "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall.bat" amd64
cd C:\\vagrant

set CMAKE_VS_PLATFORM_NAME=Win64
.\\build.bat -t local -B Release -i C:\\ASNeG -vs "Visual Studio 15 2017 Win64"
.\\build.bat -t tst -B Release -s C:\\ASNeG -vs "Visual Studio 15 2017 Win64"

SCRIPT

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.memory = 2048
    v.cpus = 4
  end

  config.vm.guest = :windows
  config.vm.communicator = :winrm
  config.ssh.insert_key = false
  config.vm.box = "flipback/asneg-dev-tool"
  config.vm.provision "shell",  inline: $script
end
