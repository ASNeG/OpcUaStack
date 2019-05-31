pipeline {
  agent any
  stages {
    stage('error') {
      steps {
        sh 'sh build.sh -t local'
        cleanWs(cleanWhenSuccess: true)
      }
    }
  }
}