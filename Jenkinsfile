pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'sh build.sh -t local'
        cleanWs(cleanWhenSuccess: true)
      }
    }
  }
}