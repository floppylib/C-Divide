param(
    [Parameter(Mandatory = $true)]
    [string]$BinaryPath
)

$ErrorActionPreference = "Stop"

$resolved = Resolve-Path -LiteralPath $BinaryPath -ErrorAction SilentlyContinue
if (-not $resolved) {
    throw "Binary not found: $BinaryPath"
}

$source = $resolved.Path
if ([System.IO.Path]::GetFileName($source) -ne "cdiv.exe") {
    Write-Warning "The file is not named cdiv.exe; it will be installed as cdiv.exe."
}

$installDir = Join-Path $env:LOCALAPPDATA "Programs\C-Divide\bin"
New-Item -ItemType Directory -Force -Path $installDir | Out-Null
Copy-Item -LiteralPath $source -Destination (Join-Path $installDir "cdiv.exe") -Force

$userPath = [Environment]::GetEnvironmentVariable("Path", "User")
$parts = @()
if ($userPath) { $parts = $userPath -split ";" | Where-Object { $_ } }

if ($parts -notcontains $installDir) {
    $newPath = (@($parts) + $installDir) -join ";"
    [Environment]::SetEnvironmentVariable("Path", $newPath, "User")
}

if (($env:Path -split ";") -notcontains $installDir) {
    $env:Path = "$env:Path;$installDir"
}

Write-Host "C÷ installed to $installDir"
Write-Host "Try: cdiv help"
Write-Host "Open a new terminal if another window does not recognize the command."
