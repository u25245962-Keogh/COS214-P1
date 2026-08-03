CXX = g++
CXXFLAGS = -std=c++11 -Wall

engine: main.cpp TransformationRegistry.cpp CheckpointManager.cpp Pipeline.cpp Connector.cpp Transformation.cpp PostgresFactory.cpp ConnectorFactory.cpp RunCheckpoint.cpp PostgresConnector.cpp
	$(CXX) $(CXXFLAGS) main.cpp TransformationRegistry.cpp CheckpointManager.cpp Pipeline.cpp Connector.cpp Transformation.cpp PostgresFactory.cpp ConnectorFactory.cpp RunCheckpoint.cpp PostgresConnector.cpp -o engine

clean:
	rm -f engine
