Function MyClean {
    [OutputType([System.Void])]
    param(
        [switch]$run
    )

    Get-ChildItem -Path "$($PSScriptRoot)/dist" | Where-Object { 
        $_.FullName -match ".obj" `
            -or $_.FullName -match ".pdb" `
            -or $_.FullName -match ".idb" `
            -or $_.FullName -match ".ilk" 
    } | ForEach-Object {
        Remove-Item $_.FullName;
    }

}
try {

    if ($env:OS -match "Windows") {
    
        MyClean;

        

        Push-Location src;
    
        cmd /s /v /c "build.bat";
    
        Write-Host "last exit code $LASTEXITCODE";
    
        if ($LASTEXITCODE -ne 0) {
            exit $LASTEXITCODE;
        }
    
        Pop-Location;
    
        if ($run) {
            & "$($PSScriptRoot)/dist/hello-qt.exe";
        }
    }
    else {
        # build somehow in another OS here assuming someone else has powershell installed
    }
}
catch {
    Pop-Location
}

Set-Location $PSScriptRoot;