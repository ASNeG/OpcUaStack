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
            sh 'docker-compose build'
            sh 'docker-compose run stack sh build.sh -t tst -j 4 -B Release --test-with-server opc.tcp://demo_server:8889 --server-pki-path /tmp/'
          }
        }

        stage('build_windows') {
          steps {
            script {
              sh('basename $PWD > DIRNAME.txt')
              env.BUILDDIRNAME = 'C:\\build\\' + readFile('DIRNAME.txt').trim()
            }

            dir('/root/WinBuildServer') {
              sh 'vagrant powershell -c "cd $BUILDDIRNAME; C:\\build_vs.bat -t local -B Release -i $BUILDDIRNAME\\.ASNeG -vs \\"Visual Studio 15 2017 Win64\\""'
              sh 'vagrant powershell -c "cd $BUILDDIRNAME; C:\\build_vs.bat -t tst -B Release -s $BUILDDIRNAME\\.ASNeG -vs \\"Visual Studio 15 2017 Win64\\""'
            }

          }
        }
      }
    }

    stage('test_linux') {
      steps {
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackCoreTest --log_format=XML --log_sink=core_results.xml --log_level=all --report_level=no'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackServerTest --log_format=XML --log_sink=server_results.xml --log_level=all --report_level=no'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackClientTest --log_format=XML --log_sink=client_results.xml --log_level=all --report_level=no'
        sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack ./OpcUaStackPubSubTest --log_format=XML --log_sink=pubsub_results.xml --log_level=all --report_level=no'
      }
    }
  }

  post {
    always {
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat core_results.xml > core_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat server_results.xml > server_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat client_results.xml > client_results.xml || true'
      sh 'docker-compose run -w /OpcUaStack/build_tst_Release stack cat pubsub_results.xml > pubsub_results.xml || true'
      xunit (
        thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
        tools: [ BoostTest(pattern: '*_results.xml') ])

      sh 'docker-compose down --volumes'
    }
  }
}
