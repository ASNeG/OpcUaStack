$script = <<-SCRIPT
'@echo on
set currPath=%cd%
call "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
@echo on
cd %currPath%
set PreferredToolArchitecture=x64
.\\build.bat %*' | Out-File 'C:\\build_vs.bat' -Encoding Ascii
SCRIPT

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.memory = 4096
    v.cpus = 4
  end


  config.vm.guest = :windows
  config.vm.communicator = :winrm
  config.vm.box = "flipback/asneg-winbuild"
  config.vm.box_version = "1.1.0"
  config.vm.provision "shell",  inline: $script, run: "always"

  config.vm.provision "file", source: "~/.ssh/id_rsa.pub", destination: "~/.ssh/authorized_keys"

  config.ssh.insert_key = false
  config.ssh.private_key_path = ["~/.ssh/id_rsa", "~/.vagrant.d/insecure_private_key"]


  config.ssh.insert_key = false
end
