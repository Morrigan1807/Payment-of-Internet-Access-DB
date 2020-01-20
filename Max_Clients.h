#pragma once

namespace PaymentofInternetAccess {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Xml;

	/// <summary>
	/// Сводка для Max_Clients
	/// </summary>
	public ref class Max_Clients : public System::Windows::Forms::Form
	{
	public:
		Max_Clients(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			saveFileDialog1->Filter = "Монохромный рисунок (*.bmp)|*.bmp|All files(*.*)|*.*";
			saveFileDialog1->DefaultExt = ".bmp";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Max_Clients()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  exit;
	protected:
	private: System::Windows::Forms::Button^  Reload_diagram;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;

	public: Form^ general;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  save;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;

	public:

	public:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Max_Clients::typeid));
			this->exit = (gcnew System::Windows::Forms::Button());
			this->Reload_diagram = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->save = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// exit
			// 
			this->exit->Location = System::Drawing::Point(887, 457);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(75, 23);
			this->exit->TabIndex = 9;
			this->exit->Text = L"Выйти";
			this->exit->UseVisualStyleBackColor = true;
			this->exit->Click += gcnew System::EventHandler(this, &Max_Clients::exit_Click);
			// 
			// Reload_diagram
			// 
			this->Reload_diagram->Location = System::Drawing::Point(269, 52);
			this->Reload_diagram->Name = L"Reload_diagram";
			this->Reload_diagram->Size = System::Drawing::Size(131, 21);
			this->Reload_diagram->TabIndex = 8;
			this->Reload_diagram->Text = L"Построить диаграмму";
			this->Reload_diagram->UseVisualStyleBackColor = true;
			this->Reload_diagram->Click += gcnew System::EventHandler(this, &Max_Clients::Reload_diagram_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(40, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Выберите день:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"MM.yyyy";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(43, 52);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 6;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(43, 93);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Berry;
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Количество клиентов за сутки";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(919, 347);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			// 
			// save
			// 
			this->save->Location = System::Drawing::Point(439, 52);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(127, 20);
			this->save->TabIndex = 10;
			this->save->Text = L"Сохранить диаграмму";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &Max_Clients::save_Click);
			// 
			// Max_Clients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(974, 492);
			this->Controls->Add(this->save);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->Reload_diagram);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->chart1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Max_Clients";
			this->Text = L"Количество клиентов за сутки";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Max_Clients::Max_Clients_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exit_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		general->Enabled = true;
		this->Close();
	}
private: System::Void Max_Clients_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
{
	general->Enabled = true;
}
private: System::Void Reload_diagram_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->chart1->Series["Количество клиентов за сутки"]->Points->Clear();
	String^ db = "Data Source=NIAGARA\\SQLEXPRESS;Initial Catalog=CourseProject;ApplicationIntent=ReadWrite;Integrated Security=SSPI";
	SqlConnection^ connect = gcnew SqlConnection(db);
	SqlCommand^ command = connect->CreateCommand();
	command->CommandText = "SELECT T_start,T_end FROM Seance join Connections ON Seance.ID_connection = Connections.ID_connection WHERE Seance.S_date = CONVERT(DATE, '"
		+ dateTimePicker1->Text->ToString() + "', 104)";
	command->Connection = connect;
	SqlDataReader^ dr;
	connect->Open();
	dr = command->ExecuteReader();
	Generic::List <Generic::KeyValuePair<String^, String^>>^ conns = gcnew Generic::List<Generic::KeyValuePair<String^, String^>>();
	while (dr->Read())
	{
		conns->Add(Generic::KeyValuePair<String^, String^>::KeyValuePair(dr[0]->ToString(), dr[1]->ToString()));
	}
	Generic::Dictionary<String^, Generic::KeyValuePair<String^, int>>^ diag_data = gcnew Generic::Dictionary<String^, Generic::KeyValuePair<String^, int>>();

	for (int k = 0; k < 24; k++)
	{
		diag_data->Add(k.ToString() + ":00", Generic::KeyValuePair<String^, int>::KeyValuePair((k + 1).ToString() + ":00", 0));
		for (int i = 0; i < conns->Count; i++)
		{
			if (String::Compare(conns[i].Value, k.ToString() + ":00") >= 0)
			{
				if (String::Compare(conns[i].Key, k.ToString() + ":00") <= 0)
				{
					diag_data[k.ToString() + ":00"] = Generic::KeyValuePair<String^, int>::KeyValuePair((k + 1).ToString() + ":00", diag_data[k.ToString() + ":00"].Value + 1);
				}
				else
					if (String::Compare(conns[i].Value, (k + 1).ToString() + ":00") <= 0)
					{
						diag_data[k.ToString() + ":00"] = Generic::KeyValuePair<String^, int>::KeyValuePair((k + 1).ToString() + ":00", diag_data[k.ToString() + ":00"].Value + 1);
					}
			}
		}
		this->chart1->Series["Количество клиентов за сутки"]->Points->AddXY(k.ToString() + ":00 - " + (k + 1).ToString() + ":00", diag_data[k.ToString() + ":00"].Value);
	}
	dr->Close();
	connect->Close();
}
private: System::Void save_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult(1))
	{
		chart1->SaveImage((saveFileDialog1->FileName), System::Drawing::Imaging::ImageFormat::Bmp);
	}
}
};
}
