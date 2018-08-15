- [zookeeper란 무엇인가?](https://unagi44.wordpress.com/2015/09/10/zookeeper%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80/)

* Ephemeral Node: 노드를 생성한 클라이언트의 세션이 연결되어 있을 경우만 유효하다. 즉 클라이언트 연결이 끊어지는 순간 삭제 된다. 이를 통해서 클라이언트가 연결이 되어있는지 아닌지를 판단하는데 사용할 수 있다. 현 클라이언트에서 “quit” 명령어를 통해 connection을 close 한 뒤 다시 zkServer에 접속해보면 Ephemeral Node가 삭제된 것을 확인이 가능합니다.

* create -e /eph '' 

- [Zookeeper Watch](https://unagi44.wordpress.com/2015/09/10/zookeeper-watch/)

* Watch 기능은 Zookeeper 클라이언트가 특정 znode에 Watch를 설정해 놓아야 사용할 수 있습니다. Watch를 설정한 노드에 변경이 생기면 watch를 설정한 client에게 event change를 알려줍니다. event change를 알리고 나면 해당 Watcher는 삭제됩니다.

- [ZooKeeper - 시작하기](http://opennote46.tistory.com/115)

```
tickTime=2000
dataDir=/tmp/zookeeper
clientPort=2181
```

* tickTime - 주키퍼에서 사용하는 기본 시간 단위 밀리세컨드. heartbeat를 위해 사용되면 최소 세션 타임아웃은 tickTime의 두배이다.
* dataDir - in-memory 데이터베이스의 스냅샷을 저장할 위치. 데이터베이스의 갱신 로그이다.
* clientPort - 클라이언트 연결을 위한 사용되는 listen 포트

- [ZooKeeper Watches](https://zookeeper.apache.org/doc/current/zookeeperProgrammers.html#ch_zkWatches)

* ZooKeeper as maintaining two lists of watches: data watches and child watches. getData() and exists() set data watches. getChildren() sets child watches. Alternatively, it may help to think of watches being set according to the kind of data returned. getData() and exists() return information about the data of the node, whereas getChildren() returns a list of children. Thus, setData() will trigger data watches for the znode being set (assuming the set is successful). A successful create() will trigger a data watch for the znode being created and a child watch for the parent znode. A successful delete() will trigger both a data watch and a child watch (since there can be no more children) for a znode being deleted as well as a child watch for the parent znode.



- [Zookeeper 소개](https://www.slideshare.net/madvirus/zookeeper-34888385)

* 부모 znode에 getChildren로 Watch 등록하고, getChildren 결과로 목록 갱신. NodeChildrenChanged 이벤트 수신 시 위 과정 재실행.

- [ZooKeeperの導入](https://qiita.com/soushiy/items/f4d2d91d7ac79669e0dd)
- [Zookeeper Tutorial](https://www.tutorialspoint.com/zookeeper/index.htm)
- [ZooKeeper 분산 코디네이터 - 예제 코딩편(java)](http://blog.naver.com/PostView.nhn?blogId=alice_k106&logNo=220620934774)
- [ZooKeeper를 활용한 Redis Cluster 관리](https://d2.naver.com/helloworld/294797)
- [손쉽게 사용하는 ZooKeeper 스토리지, Zoopiter!](https://d2.naver.com/helloworld/583580)
