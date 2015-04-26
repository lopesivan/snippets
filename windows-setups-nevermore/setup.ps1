# -*- powershell -*-

function Install-NeededFor {
param([string]$packageName = '')
  if ($packageName -eq '') {return $false}

  $yes = '6'
  $no = '7'
  $msgBoxTimeout='-1'

  $answer = $msgBoxTimeout
  try {
    $timeout = 1
    $question = "Do you need to install $($packageName)? Defaults to 'Yes' after $timeout seconds"
    $msgBox = New-Object -ComObject WScript.Shell
    $answer = $msgBox.Popup($question, $timeout, "Install $packageName", 0x4)
  }
  catch {}

  if ($answer -eq $yes -or $answer -eq $msgBoxTimeout) {
    write-host 'returning true'
    return $true
  }
  return $false
}

#install chocolatey
if (Install-NeededFor 'chocolatey') {
  iex ((new-object net.webclient).DownloadString('http://chocolatey.org/install.ps1'))
}

# install nuget
cinstm nuget.commandline

# install other packages
cinstm packages.config
