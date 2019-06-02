pipeline {
  agent any
  stages {
    stage('cppcheck') {
      steps {
        sh 'cppcheck --xml --xml-version=2 ./src 2> cppcheck.xml'
      }
    }
    stage('build') {
      steps {
        sh 'sh build.sh -t local'
  	sh 'docker-compose run  --name test_container stack sh build.sh -t tst -j 4 -B Release --test-with-server opc.tcp://demo_server:8889'
        sh 'docker commit test_container opcuastack_stack'
      }
    }

    stage('test') {
      steps {
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackCoreTest'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackServerTest'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackClientTest'
      }
    }
  }

  post {
    always {
      sh 'docker rm test_container'
    }
  }
}
