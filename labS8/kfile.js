const fs = require('fs');

let project = new Project('LabS8');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('../Deployment');

// fs.copyFileSync(process.cwd()+'/labS8J1/test_input.txt','./Deployment/test_input.txt');

resolve(project);
