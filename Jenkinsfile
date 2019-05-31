pipeline {
  agent any
  stages {
    stage('error') {
      steps {
        sh 'build.sh -t local'
      }
    }
  }
}