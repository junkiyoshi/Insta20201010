#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);

	for (int i = 0; i < 20; i++) {

		auto particle = make_unique<Particle>();
		this->particle_list.push_back(move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (auto& particle : this->particle_list) {

		particle->update(this->particle_list);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofMesh mesh;
	mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);

	for (auto& particle : this->particle_list) {
		
		mesh.addVertices(particle->log);
	}

	for (int i = 0; i < mesh.getNumVertices(); i++)	{

		for (int k = i + 1; k < mesh.getNumVertices(); k++) {

			auto distance = glm::distance(mesh.getVertex(i), mesh.getVertex(k));
			if (distance < 25) {

				mesh.addIndex(i); mesh.addIndex(k);
			}
		}

	}

	ofSetColor(39);
	mesh.drawVertices();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}