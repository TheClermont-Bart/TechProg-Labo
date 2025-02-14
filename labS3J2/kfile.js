const fs = require('fs');



let project = new Project('LabS3J2');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('../Deployment');

fs.copyFileSync(process.cwd()+'/labS3J2/test_input.txt','./Deployment/test_input.txt');

resolve(project);
