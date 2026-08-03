#include "TransformationRegistry.h"
#include "CheckpointManager.h"
#include "Pipeline.h"
#include "Connector.h"
#include "Transformation.h"
#include "PostgresFactory.h"
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

int main(){

TransformationRegistry* registry = new TransformationRegistry();


DeduplicateStep* d = new DeduplicateStep();
registry->registerStep("dedup", d );

AggregateByRegionStep* a = new AggregateByRegionStep();
registry->registerStep("aggregate", a );

ConnectorFactory* cf = new PostgresFactory();

BatchPipeline* bp = new BatchPipeline(cf);

bp->addStep(registry->create("dedup"));
bp->addStep(registry->create("aggregate"));

CheckpointManager* cm = new CheckpointManager();
bp->run();
RunCheckpoint* cp = bp->createCheckpoint();
cm->save(cp);

delete registry;
delete d;
delete a;
delete cf;
delete bp;
delete cm;

    return 0;
}
