pipeline {
  agent any
  stages {
    stage('cppcheck') {
      steps {
        sh 'cppcheck --xml --xml-version=2 ./src 2> cppcheck.xml'
      }
    }
    stage('build-local') {
      steps {
        sh 'sh build.sh -t local'
        cleanWs(cleanWhenSuccess: true)
      }
    }
  }
}