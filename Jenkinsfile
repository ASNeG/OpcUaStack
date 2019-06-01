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
            sh 'cppcheck --xml --xml-version=2 ./src 2> cppcheck.xml'
          }
        }
      }
    }
    stage('') {
      steps {
        sh 'sh build.sh -t local'
        cleanWs(cleanWhenSuccess: true)
      }
    }
  }
}