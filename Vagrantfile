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
            setx $matches[1] $matches[2]
        }
        else {
            $_
        }
    }

    Remove-Item $tempFile
    setx PreferredToolArchitecture x64
}


Invoke-BatchFile "C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\VC\\vcvarsall.bat" amd64
cd C:\\vagrant


SCRIPT

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.memory = 1024
    v.cpus = 2 
  end

  config.vm.guest = :windows
  config.vm.communicator = :winrm
  config.vm.box = "flipback/asneg-dev-tool"
  config.vm.box_version = "1.1.1"
  config.vm.provision "shell",  inline: $script

  config.ssh.insert_key = false
end
