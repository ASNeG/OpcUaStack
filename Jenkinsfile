pipeline {
  agent any
  stages {
    stage('cppcheck') {
      steps {
        sh 'cppcheck --xml --xml-version=2 ./src 2> cppcheck.xml'
      }
    }
    stage('build') {
      parallel {
        stage('build_linux') {
          steps {
            sh 'docker-compose build --pull'
            sh 'docker-compose run stack sh build.sh -t tst -j 2 -B Release --test-with-server opc.tcp://asneg-demo:8889 --server-pki-path /tmp/'
          }
        }

        stage('build_windows') {
          steps {
            script {
              sh('basename $PWD > DIRNAME.txt')
              env.BUILDDIRNAME = 'C:\\build\\' + readFile('DIRNAME.txt').trim()
            }

            sh 'ssh 127.0.0.1 -l vagrant -p 2222 "cd $BUILDDIRNAME && C:\\build_vs.bat -t local -B Release -i $BUILDDIRNAME\\.ASNeG -vs \\"Visual Studio 15 2017 Win64\\" -j 2"'
            sh 'ssh 127.0.0.1 -l vagrant -p 2222 "cd $BUILDDIRNAME && C:\\build_vs.bat -t tst -B Release -s $BUILDDIRNAME\\.ASNeG -vs \\"Visual Studio 15 2017 Win64\\" -j 2"'

          }
        }
      }
    }

    stage('test_linux') {
      steps {
        timeout(time: 5, unit: "MINUTES") {
          sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackCoreTest --log_format=XML --log_sink=core_results.xml --log_level=all --report_level=no'
          sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackServerTest --log_format=XML --log_sink=server_results.xml --log_level=all --report_level=no'
          sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackPubSubTest --log_format=XML --log_sink=pubsub_results.xml --log_level=all --report_level=no'
          retry (3) {
            sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackClientTest --log_format=XML --log_sink=client_results.xml --log_level=all --report_level=no'
          }
        }
      }
    }

    stage('win_deploy') {
      when {
        branch 'Release4'
      }
      steps {
        sh 'ssh 127.0.0.1 -l vagrant -p 2222 "cd $BUILDDIRNAME && C:\\build_vs.bat -t local -B Release -i C:\\ASNeG -vs \\"Visual Studio 15 2017 Win64\\" -j 2"'
      }
    }

  }

  
  post {
    fixed {
      slackSend(color:'#BDFFC3', message:"Build Fixed - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.B»
    }

    failure {
      slackSend(color:'#FF9FA1', message:"Build Failed - ${env.JOB_NAME} ${env.BUILD_NUMBER} (<${env.»
    }

    always {
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat core_results.xml > core_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat server_results.xml > server_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat client_results.xml > client_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat pubsub_results.xml > pubsub_results.xml || true'
      xunit (
        thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
        tools: [ BoostTest(pattern: '*_results.xml') ])

        
      sh 'docker-compose down --volumes --rmi local'
      deleteDirs()
    }
  }
}
