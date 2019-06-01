pipeline {
  agent any
  stages {
    stage('Build') {
      parallel {
        stage('Build') {
          steps {
            sh 'sh build.sh -t local'
            cleanWs(cleanWhenSuccess: true)
          }
        }
        stage('CPP check') {
          steps {
            sh 'echo "hello world"'
          }
        }
      }
    }
  }
}