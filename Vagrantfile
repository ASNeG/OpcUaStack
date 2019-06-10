$script = <<-SCRIPT
Build "-t local -B Release -i C:\\ASNeG -vs Ninja"
Build "-t tst -B Release -s C:\\ASNeG -vs Ninja"
SCRIPT

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.memory = 2048
    v.cpus = 4
  end

  config.vm.guest = :windows
  config.vm.communicator = :winrm
  config.vm.box = "flipback/asneg-winbuild"
  config.vm.box_version = "1.0.0"
  config.vm.provision "shell",  inline: $script, run: "always"

  config.ssh.insert_key = false
end
